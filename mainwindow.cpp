#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Быки и коровы");
    setAttribute(Qt::WA_DeleteOnClose);
    addLabelToVector(ui->user_player, user_results);
    addLabelToVector(ui->opp_player, opp_results);
}

void MainWindow::addLabelToVector(QVBoxLayout *layout,
                                  QVector <ResultOfTry> results) {
    for (int i = 0; i < 10; i++) {
        QHBoxLayout *l = new QHBoxLayout();
        layout->addLayout(l);
        QLabel *number = new QLabel();
        QLabel *bulls = new QLabel();
        QLabel *cows = new QLabel();
        l->addWidget(number, 2);
        l->addWidget(bulls, 1);
        l->addWidget(cows, 1);
        results.push_back({number, bulls, cows});
    }
}

MainWindow::~MainWindow() {
    delete user;
    delete opp;
    delete ui;
    delete server;
    delete client;
}


void MainWindow::on_inputChosenNumber_clicked() {
    getInput();
    clearInput();
    blockInput();

    if (input.is_4_digit()) {
        showNumberToUser();
        user = new Player(input.number);
        ui->inputChosenNumber->hide();
        isItServer();
        if (isServer)
            unlockInput();
    }
    else
        repeatInput();
}

void MainWindow::on_inputGuessedNumber_clicked() {
    getInput();
    clearInput();
    blockInput();

    if (input.is_4_digit()) {
        if (isServer)
            server->sendToClient(server->sockets[0], input.number);
        else
            client->sendToServer(input.number);
    }
    else
        repeatInput();
}

void MainWindow::isItServer() {
    if (server == nullptr) {
        isServer = false;
        connect(client->tcpSocket, &QTcpSocket::readyRead,
                this, &MainWindow::slotGetOppNumber);
    }
    else {
        isServer = true;
        connect(server->sockets[0], &QTcpSocket::readyRead,
            this, &MainWindow::slotGetOppNumber);
    }
}

void MainWindow::getInput() {
    input = {ui->input->text()};
}

void MainWindow::clearInput() {
    ui->input->clear();
}

void MainWindow::blockInput() {
    ui->input->setReadOnly(1);
}

void MainWindow::unlockInput() {
    ui->input->setReadOnly(0);
}

void MainWindow::showNumberToUser() {
    QString setting_text =
            QString("Ваше число: ") + input.number;
    ui->pointing_for_user->setText(setting_text);
    ui->user_number->setText((input.number));
}

void MainWindow::repeatInput() {
    ui->pointing_for_user->setText("Введите число из 4 цифр");
    ui->input->setReadOnly(0);
}

void MainWindow::slotGetOppNumber() {
    if (!opp) {
        if (isServer)
            opp = new Player(server->data);
        else
            opp = new Player(client->data);
    }
//    if (isServer) {

//    }
}

void MainWindow::showTableHeads() {
    showTableHead(user_results);
    showTableHead(opp_results);
}

void MainWindow::showTableHead(QVector <ResultOfTry> results) {
    results[0].number->setText("Введенное число");
    results[0].bulls->setText("Быки");
    results[0].cows->setText("Коровы");
}

void MainWindow::gameRules() {
//    Rules r;
//    r.show();
}

