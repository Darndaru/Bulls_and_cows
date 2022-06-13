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

public:
    explicit ServerWindow(MainWindow *parent = nullptr);
    ~ServerWindow();

private:
    void generatePortNumber();
    void createServer();

public slots:
    void slotConnectionEstablished();

signals:
    void menu();

private:
    Ui::ServerWindow *ui;
    MainWindow *w;

    int port_number;
};

#endif // SERVERWINDOW_H
