#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    w = parent;
    this->setWindowTitle("Создание игры");
    setAttribute(Qt::WA_DeleteOnClose);
}

ServerWindow::~ServerWindow() {
    delete ui;
}
