#include "clientwindow.h"
#include "ui_clientwindow.h"

#include <dos.h>

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
    QString port_text = ui->port_number->text();

    bool isConverted;
    port = port_text.toInt(&isConverted);
    if (!isConverted) {
        ui->label_result->setText("Номер порта некорректный.");
        return;
    }

    w->client = new MyClient(ip, port);
    connect(w->client->tcpSocket, &QTcpSocket::connected,
            this, &ClientWindow::slotConnectionEstablished);
    ui->label_result->setText("Ожидайте.");
    _sleep(20);
    ui->label_result->setText("Попробуйте еще раз.");
}

void ClientWindow::slotConnectionEstablished() {
    w->setEnabled(1);
    w->showTableHeads();
    this->close();
}
