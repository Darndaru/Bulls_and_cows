#include "result.h"
#include "ui_result.h"

Result::Result(int result,
               MainWindow *w,
               QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result),
    w(w)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    switch (result) {
        case -1: {
            showResult("Проигрыш", "Вы проиграли!\n"
                                   "Но у вас еще все впереди!");
            break;
        }
        case 0: {
            showResult("Ничья", "Ничья!\n"
                                "Вы играли слишком долго.");
            break;
        }
        case 1: {
            showResult("Победа", "Поздравляем с победой!\n");
            break;
        }
        default: {
            showResult("Ошибка", "Результат неизвестен."
                                 "Почерк неразборчивый");
            break;
        }
    }
}

void Result::showResult(QString title,
                        QString text) {
    setWindowTitle(title);
    ui->result->setText(text);
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
