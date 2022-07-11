#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ClientWindow;
}

class MainWindow;

class ClientWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::ClientWindow *ui;
    MainWindow *w;

    QString ip;
    int port;

    bool isPortNumberCorrect = false;

public:
    explicit ClientWindow(MainWindow *parent = nullptr);
    ~ClientWindow();

private:
    void getIpAddress();
    void getPortNumber();
    void createClient();

signals:
    void menu();

private slots:
    void on_play_button_clicked();

public slots:
    void slotConnectionEstablished();
};

#endif // CLIENTWINDOW_H
