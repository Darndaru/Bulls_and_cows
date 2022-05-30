#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    sw = new ServerWindow();
    cw = new ClientWindow();
    connect(sw, &ServerWindow::menu, this, &MainMenu::show);
    connect(cw, &ClientWindow::menu, this, &MainMenu::show);
}

MainMenu::~MainMenu() {
    delete ui;
    delete w;
    delete sw;
    delete cw;
}


void MainMenu::on_server_button_clicked() {
    sw->show();
    this->close();
}

void MainMenu::on_client_button_clicked() {
    cw->show();
    this->close();
}

void MainMenu::on_quit_clicked() {
    w->close();
    this->close();
}
