#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

class QTcpSocket;


class MyServer : QObject {
    Q_OBJECT

private:
    QTcpServer *tcpServer;
    quint16 nextBlockSize;
    QString data;

private:
    void sendToClient(QTcpSocket *socket, const QString &str);

public:
    MyServer(int port);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};

#endif // MYSERVER_H
