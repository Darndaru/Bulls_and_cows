#include "result.h"
#include "ui_result.h"

Result::Result(int result, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    switch (result) {
    case -1: {
        setWindowTitle("Проигрыш");
        ui->result->setText("Вы проиграли!\n"
                            "Но у вас еще все впереди!");
        break;
    }
    case 0: {
        setWindowTitle("Ничья");
        ui->result->setText("Ничья!\n"
                            "Вы играли слишком долго.");
        break;
    }
    case 1: {
        setWindowTitle("Победа");
        ui->result->setText("Поздравляем с победой!\n");
        break;
    }
    default: {
        setWindowTitle("Ошибка");
        ui->result->setText("Результат неизвестен."
                            "Почерк неразборчивый");
        break;
    }
    }
}

Result::~Result()
{
    delete ui;
}

void Result::on_quit_clicked() {

}


void Result::on_startOver_clicked()
{

}

