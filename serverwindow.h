#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ServerWindow(MainWindow *parent = nullptr);
    ~ServerWindow();

signals:
    void menu();

private:
    Ui::ServerWindow *ui;
    MainWindow *w;
};

#endif // SERVERWINDOW_H
