#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    w = parent;
    this->setWindowTitle("Создание игры");

    generatePortNumber();
    createServer();

    setAttribute(Qt::WA_DeleteOnClose);
}

void ServerWindow::generatePortNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(5000,6500);
    port_number = dist(gen);
    QString port = QString::number(port_number);
    ui->port->setText(QString(port));
}

void ServerWindow::createServer() {
    w->server = new MyServer(port_number);
    connect(w->server, &MyServer::connected,
            this, &ServerWindow::slotConnectionEstablished);
    connect(w->server, &MyServer::connected,
            w, &MainWindow::slotConnectionEstablished);
}

ServerWindow::~ServerWindow() {
    delete ui;
}

void ServerWindow::slotConnectionEstablished() {
    this->close();
}
