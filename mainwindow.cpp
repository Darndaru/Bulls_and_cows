#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_input_chosen_number_button_clicked() {
    input_number = get_input();

    clear_input();
    block_input();

    if (is_4_digit_number(input_number)) {
        player->set_number(input_number);
        show_number_to_user();
        input_chosen_number_button_close();
    }
    else
        repeat_input();
}

QString MainWindow::get_input() {
    return ui->input->text();
}

void MainWindow::clear_input() {
    ui->input->clear();
}

void MainWindow::block_input() {
    ui->input->setReadOnly(1);
}

bool MainWindow::is_4_digit_number(QString input) {
    if (input.length() != 4)
        return false;

    for (QChar symbol : input)
        if (!symbol.isDigit())
            return false;
    return true;
}

void MainWindow::show_number_to_user() {
    QString setting_text = QString("Ваше число: ") + player->get_number();
    ui->pointing_for_user->setText(setting_text);
}

void MainWindow::input_chosen_number_button_close() {
    ui->input_chosen_number_button->close();
}

void MainWindow::repeat_input() {
    ui->pointing_for_user->setText("Введите число из 4 цифр");
    ui->input->setReadOnly(0);
}



void MainWindow::game_rules() {
    Rules r;
    r.show();
}

