#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QVector>

class MyServer : public QObject {
    Q_OBJECT

private:
    quint16 nextBlockSize;
    QTcpServer *tcpServer;

public:
    QVector <QTcpSocket*> sockets;
    QString data;
    void sendToClient(QTcpSocket *socket, const QString &str);

public:
    MyServer(int port);

signals:
    void read();
    void connected();

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};

#endif // MYSERVER_H
