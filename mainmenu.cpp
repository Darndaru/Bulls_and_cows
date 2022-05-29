#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    sw = new ServerWindow();
    cw = new ClientWindow();
    connect(sw, &ServerWindow::menu, this, &MainMenu::show);
    connect(cw, &ClientWindow::menu, this, &MainMenu::show);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_server_button_clicked() {
    sw->show();
    this->close();
}

