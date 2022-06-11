#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(MainWindow *parent = nullptr);
    ~ClientWindow();

signals:
    void menu();

private slots:
    void on_play_button_clicked();

public slots:
    void slotConnectionEstablished();

private:
    Ui::ClientWindow *ui;
    MainWindow *w;

    QString ip;
    int port;
};

#endif // CLIENTWINDOW_H
