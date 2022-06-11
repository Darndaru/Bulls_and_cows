#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyClient : public QObject {
    Q_OBJECT

private:
    quint16 nextBlockSize;

public:
    QTcpSocket *tcpSocket;
    QString data;

public:
    MyClient(const QString &host, int port);
    void sendToServer(QString data);

private:
    void slotReadyRead();
//    void slotError(QAbstractSocket::SocketError);
    void slotConnected();


};

#endif // MYCLIENT_H
