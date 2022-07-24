#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow),
    w(parent)
{
    ui->setupUi(this);
    this->setWindowTitle("Подключение к серверу");
    setAttribute(Qt::WA_DeleteOnClose);
}

ClientWindow::~ClientWindow() {
    delete ui;
}

void ClientWindow::on_play_button_clicked() {
    getIpAddress();
    getPortNumber();

    if (!isPortNumberCorrect) {
        ui->label_result->setText("Номер порта некорректный.");
        return;
    }

    createClient();
}

void ClientWindow::getIpAddress() {
    ip = ui->ip_address->text();
}

void ClientWindow::getPortNumber() {
    QString port_text = ui->port_number->text();
    port = port_text.toInt(&isPortNumberCorrect);
}

void ClientWindow::createClient() {
    w->client = new MyClient(ip, port);
    connect(w->client, &MyClient::connected,
            this, &ClientWindow::slotConnectionEstablished);
    connect(w->client, &MyClient::connected,
            w, &MainWindow::slotConnectionEstablished);
}

void ClientWindow::slotConnectionEstablished() {
    this->close();
}
