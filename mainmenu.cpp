#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    w = parent;
    this->setWindowTitle("Меню");
    setAttribute(Qt::WA_DeleteOnClose);
}

MainMenu::~MainMenu() {
    delete ui;
}


void MainMenu::on_server_button_clicked() {
    ServerWindow *sw = new ServerWindow(w);
    connect(sw, &ServerWindow::menu, this, &MainMenu::show);
    sw->setWindowModality(Qt::ApplicationModal);
    this->close();
    sw->show();
}

void MainMenu::on_client_button_clicked() {
    ClientWindow *cw = new ClientWindow(w);
    connect(cw, &ClientWindow::menu, this, &MainMenu::show);
    cw->setWindowModality(Qt::ApplicationModal);
    this->close();
    cw->show();
}

void MainMenu::on_quit_clicked() {
    w->close();
    this->close();
}
