#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , u_num_of_attempts(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Быки и коровы");
    setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow() {
    delete user;
    delete ui;
    delete server;
    delete client;
}

void MainWindow::showTableHeads() {
    ui->u_number->setText("Введенное число");
    ui->u_bulls->setText("Быки");
    ui->u_cows->setText("Коровы");
    ui->o_number->setText("Введенное число");
    ui->o_bulls->setText("Быки");
    ui->o_cows->setText("Коровы");
}

void MainWindow::on_inputChosenNumber_clicked() {
    getInput();
    clearInput();
    blockInput();

    if (input.is_4_digit()) {
        sendNumber(input.number);

        if (!opp) {
            showNumberToUser();
            opp = new Player(input.number);
        }
        else {
            user->set_guessed_number(input.number);
            showUserResults();
            u_num_of_attempts++;

            checkWin(user);
            checkDraw();
        }
        ui->pointing_for_user->
                setText("Ожидайте. Очередь противника.");
    }
    else
        repeatInput();
}

void MainWindow::slotGetOppNumber() {
    if (isServer) {
        if (!user)
            user = new Player(server->data);
        else
            opp->set_guessed_number(server->data);
        server->data = "";
    }
    else {
        if (!user)
            user = new Player(client->data);
        else
            opp->set_guessed_number(client->data);
        client->data = "";
    }

    showOppResults();
    o_num_of_attempts++;

    checkWin(opp);
    checkDraw();

    ui->pointing_for_user->
        setText("Ваша очередь. Угадайте число противника.");

    unlockInput();
}

void MainWindow::checkWin(Player *player) {
    if (player->get_bulls() == 4) {
        if (player == user)
            r = new Result(1, this);
        else
            r = new Result(-1, this);
        showGameResult();
    }
}

void MainWindow::checkDraw() {
    if (u_num_of_attempts >= 18 && o_num_of_attempts >=18) {
        r = new Result(0, this);
        showGameResult();
    }
}

void MainWindow::showGameResult() {
    setEnabled(0);
    r->setWindowModality(Qt::ApplicationModal);
    r->show();
}


void MainWindow::isItServer() {
    if (server == nullptr) {
        isServer = false;
        connect(client, &MyClient::read,
                this, &MainWindow::slotGetOppNumber);
    }
    else {
        isServer = true;
        connect(server, &MyServer::read,
            this, &MainWindow::slotGetOppNumber);
    }
}

void MainWindow::getInput() {
    *input = {ui->input->text()};
}

void MainWindow::clearInput() {
    ui->input->clear();
}

void MainWindow::blockInput() {
    ui->input->setReadOnly(1);
    ui->inputChosenNumber->setEnabled(0);
}

void MainWindow::unlockInput() {
    ui->input->setReadOnly(0);
    ui->inputChosenNumber->setEnabled(1);
}

void MainWindow::showNumberToUser() {
    QString setting_text =
            QString("Ваше число: ") + input->number;
    ui->pointing_for_user->setText(setting_text);
    ui->user_number->setText((input->number));
}

void MainWindow::repeatInput() {
    ui->pointing_for_user->setText("Введите число из 4 цифр");
    ui->input->setReadOnly(0);
    ui->inputChosenNumber->setEnabled(1);
}

void MainWindow::sendNumber(QString number) {
    if (isServer)
        server->sendToClient(server->sockets[0], number);
    else
        client->sendToServer(number);
}

void MainWindow::showUserResults() {
    showResults("user", user);
}

void MainWindow::showOppResults() {
    showResults("opp", opp);
}

void MainWindow::showResults(QString player_name, Player* player) {
    QHBoxLayout *l = new QHBoxLayout();

    QLabel *number = new QLabel();
    QLabel *bulls = new QLabel();
    QLabel *cows = new QLabel();

    number->setAlignment(Qt::AlignRight);
    bulls->setAlignment(Qt::AlignRight);
    cows->setAlignment(Qt::AlignRight);

    number->setText(player->get_guessed_number());
    bulls->setText(QString::number(player->get_bulls()));
    cows->setText(QString::number(player->get_cows()));

    l->addWidget(number, 3);
    l->addWidget(bulls, 1);
    l->addWidget(cows, 1);

    if (player_name == "user")
        ui->user_player->addLayout(l);
    else
        ui->opp_player->addLayout(l);
}

void MainWindow::slotConnectionEstablished() {
    this->setEnabled(1);
    ui->pointing_for_user->setEnabled(1);
    showTableHeads();
    isItServer();
}

void MainWindow::gameRules() {
//    Rules r;
//    r.show();
}
