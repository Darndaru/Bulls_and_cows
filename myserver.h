#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QVector>

class MyServer : QObject {
    Q_OBJECT

private:
    quint16 nextBlockSize;

public:
    QTcpServer *tcpServer;
    QVector <QTcpSocket*> sockets;
    QString data;
    void sendToClient(QTcpSocket *socket, const QString &str);

public:
    MyServer(int port);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};

#endif // MYSERVER_H
