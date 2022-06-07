#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow() {
    delete player;
    delete pc;
    delete ui;
}


void MainWindow::on_input_chosen_number_button_clicked() {
    get_input();
    clear_input();
    block_input();

    if (input.is_4_digit()) {
//        player->set_hidden_number(input_number);
        show_number_to_user();
        input_chosen_number_button_close();
    }
    else
        repeat_input();
}

void MainWindow::get_input() {
     input = {ui->input->text()};
}

void MainWindow::clear_input() {
    ui->input->clear();
}

void MainWindow::block_input() {
    ui->input->setReadOnly(1);
}

void MainWindow::show_number_to_user() {
    QString setting_text =
            QString("Ваше число: ") + input.number;
    ui->pointing_for_user->setText(setting_text);
    ui->user_number->setText((input.number));
}

void MainWindow::input_chosen_number_button_close() {
    ui->input_chosen_number_button->close();
}

void MainWindow::repeat_input() {
    ui->pointing_for_user->setText("Введите число из 4 цифр");
    ui->input->setReadOnly(0);
}

void MainWindow::show_table_heads() {
    ui->label_number_0->setText("Введенное число");
    ui->label_bulls_0->setText("Быки");
    ui->label_cows_0->setText("Коровы");
    ui->label_number_1->setText("Введенное число");
    ui->label_bulls_1->setText("Быки");
    ui->label_cows_1->setText("Коровы");
}

void MainWindow::game_rules() {
    Rules r;
    r.show();
}

