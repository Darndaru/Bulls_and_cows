#include "myclient.h"

MyClient::MyClient(const QString &host, int port) {
    nextBlockSize = 0;
    tcpSocket = new QTcpSocket(this);

    tcpSocket->connectToHost(host, port);
    connect(tcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));
}

void MyClient::slotReadyRead() {
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_3);
    for(;;) {
        if (tcpSocket->bytesAvailable() < sizeof(quint16))
            break;

        in >> nextBlockSize;

        if (tcpSocket->bytesAvailable() < nextBlockSize)
            break;

        QString str;
        in >> str;

        data.append(str);
        nextBlockSize = 0;
    }
}

//void MyClient::slotError(QAbstractSocket::SocketError err) {

//}

void MyClient::sendToServer(QString data) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out << quint16(0) << data;

    out.device()->seek(0);
    out << quint16(block.size()) - sizeof(quint16);

    tcpSocket->write(block);
}
