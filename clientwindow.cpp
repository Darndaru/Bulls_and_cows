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
//    delete w;
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
    if (w->client->isConnected())
        this->close();
    else
        ui->label_result->setText(
           "Соединение не установлено. Попробуйте еще раз.");
}
