#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //инициализация
    QShortcut *keyEnter = new QShortcut(this);
    //привязка кода клавиши к объекту
    keyEnter->setKey(Qt::Key_Enter);
    //привязка объекта к слоту
    connect(keyEnter, SIGNAL(activated()), this, SLOT(slotShortrcutEnter()));

    QShortcut *keyEnterNum = new QShortcut(this);
    keyEnterNum->setKey(Qt::Key_Enter);
    connect(keyEnter, SIGNAL(activated()), this, SLOT(slotShortrcutEnter()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::slotShortrcutEnter() {
    if (ui->input_user_number_button->isEnabled()) {
        this->on_input_user_number_button_clicked();
        return;
    }
}

void MainWindow::on_input_user_number_button_clicked() {
    //считываем введенное число
    user_number = ui->input_number->text();
    //очищаем область ввода
    ui->input_number->clear();
    //делаем ввод невозможным
    ui->input_number->setReadOnly(1);
    //проверка: введенная строка - четырехзначное число
    if (!is_number(user_number)) {
        ui->pointing_for_user->setText("Введите число из 4 цифр");
        ui->input_number->setReadOnly(0);
    }
    else {
        QString chosen_number = QString(user_number);
        QString setting_text = QString("Ваше число: ");
        setting_text.push_back(chosen_number);
        ui->pointing_for_user->setText(setting_text);
        ui->input_user_number_button->close();
    }
}

bool MainWindow::is_number(QString input) {
    if (input.length() != 4)
        return false;
    for (QChar symbol : input)
        if (!symbol.isDigit())
            return false;
    return true;
}

