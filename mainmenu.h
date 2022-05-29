#ifndef MAINMENU_H
#define MAINMENU_H

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
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_server_button_clicked();

private:
    Ui::MainMenu *ui;

    ServerWindow *sw;
    ClientWindow *cw;
};

#endif // MAINMENU_H
