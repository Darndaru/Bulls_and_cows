#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(int result,
                    QWidget *parent = nullptr);
    ~Result();

private slots:
    void on_quit_clicked();

    void on_startOver_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
