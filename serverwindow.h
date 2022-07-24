#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QDialog>
#include <random>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ServerWindow *ui;
    MainWindow *w;

    int port_number;


private:
    void generatePortNumber();
    void createServer();

public:
    explicit ServerWindow(MainWindow *parent = nullptr);
    ~ServerWindow();

signals:
    void menu();

public slots:
    void slotConnectionEstablished();
};

#endif // SERVERWINDOW_H
