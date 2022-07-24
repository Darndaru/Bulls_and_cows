#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu),
    w(parent)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");
    setAttribute(Qt::WA_DeleteOnClose);
}

MainMenu::~MainMenu() {
    delete ui;
}


void MainMenu::on_server_button_clicked() {
    ServerWindow *sw = new ServerWindow(w);
    connect(sw, &ServerWindow::menu, this, &MainMenu::show);
    showConnectionWindow(sw);
}

void MainMenu::on_client_button_clicked() {
    ClientWindow *cw = new ClientWindow(w);
    connect(cw, &ClientWindow::menu, this, &MainMenu::show);
    showConnectionWindow(cw);
}

template <typename T>
void MainMenu::showConnectionWindow(T window) {
    window->setWindowModality(Qt::ApplicationModal);
    window->show();
    this->hide();
}

void MainMenu::on_quit_clicked() {
    w->close();
    this->close();
}
