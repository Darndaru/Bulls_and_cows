#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"
#include "serverwindow.h"
#include "clientwindow.h"
#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(MainWindow *parent = nullptr);
    ~MainMenu();

private slots:
    void on_server_button_clicked();
    void on_client_button_clicked();
    void on_quit_clicked();

private:
    Ui::MainMenu *ui;

    MainWindow *w;
};

#endif // MAINMENU_H
