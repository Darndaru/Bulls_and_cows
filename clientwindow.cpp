#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    w = parent;
    this->setWindowTitle("Подключение к серверу");
    setAttribute(Qt::WA_DeleteOnClose);
}

ClientWindow::~ClientWindow() {
    delete ui;
}

void ClientWindow::on_play_button_clicked() {
    ip = ui->ip_address->text();
    getPortNumber();

    if (!isPortNumberCorrect) {
        ui->label_result->setText("Номер порта некорректный.");
        return;
    }

    w->client = new MyClient(ip, port);
    connect(w->client, &MyClient::connected,
            this, &ClientWindow::slotConnectionEstablished);
    connect(w->client, &MyClient::connected,
            w, &MainWindow::slotConnectionEstablished);
}

void ClientWindow::getPortNumber() {
    QString port_text = ui->port_number->text();
    port = port_text.toInt(&isPortNumberCorrect);
}

void ClientWindow::slotConnectionEstablished() {
    this->close();
}
