#include "result.h"
#include "ui_result.h"

Result::Result(int result,
               MainWindow *w,
               QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    this->w = w;
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
    setAttribute(Qt::WA_DeleteOnClose);
}

Result::~Result() {
    w->close();
    delete w;
    delete ui;
}

void Result::on_quit_clicked() {
    w->close();
    delete w;
    this->close();
}
