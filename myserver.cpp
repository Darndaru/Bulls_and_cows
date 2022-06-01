#include "myserver.h"

MyServer::MyServer(int port) {
    tcpServer = new QTcpServer(this);
    nextBlockSize = 0;
    if (!tcpServer->listen(QHostAddress::Any, port)) {
        QMessageBox::critical (0,
                               "Server Error",
                               "Unable to start the server: "
                               + tcpServer->errorString());
        tcpServer->close();
        return;
    }

    connect(tcpServer, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));
}

void MyServer::slotNewConnection() {
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, SIGNAL(disconnected()), clientSocket,
            SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(readyRead()), this,
            SLOT(slotReadClient()));
    sendToClient(clientSocket, "Server response: Connected!");
}

void MyServer::slotReadClient() {
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_3);
    for (;;) {
        if (!nextBlockSize) {
            if (clientSocket->bytesAvailable() < sizeof (quint16))
                break;
            in >> nextBlockSize;
        }
        if (clientSocket->bytesAvailable() < nextBlockSize)
            break;

        QTime time;
        QString str;
        in >> str;

        QString strMessage = time.toString() + " " + str;
        data.append(strMessage);

        nextBlockSize = 0;
    }
}

void MyServer::sendToClient(QTcpSocket *socket, const QString &str) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion((QDataStream::Qt_5_3));
    out << quint16(0) << str;

    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));

    socket->write(block);
}
