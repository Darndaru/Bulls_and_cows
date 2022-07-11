#include "myclient.h"

MyClient::MyClient(const QString &host, int port) {
    nextBlockSize = 0;
    tcpSocket = new QTcpSocket(this);

    tcpSocket->connectToHost(host, port);
    connect(tcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(tcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
}

void MyClient::slotReadyRead() {
    QDataStream in(tcpSocket);
    qDebug() << "Client is reading";
    in.setVersion(QDataStream::Qt_5_3);
    for(;;) {
        if (!nextBlockSize) {
            if (tcpSocket->bytesAvailable() < sizeof(quint16))
                break;

            in >> nextBlockSize;
        }

        if (tcpSocket->bytesAvailable() < nextBlockSize)
            break;

        QString str;
        in >> str;

        data.append(str);
        nextBlockSize = 0;
    }
    qDebug() << "Client has read";
    emit read();
}

void MyClient::slotConnected() {
    emit connected();
}

void MyClient::sendToServer(QString data) {
    QByteArray block;
    block.clear();
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << data;

    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));

    tcpSocket->write(block);
}
