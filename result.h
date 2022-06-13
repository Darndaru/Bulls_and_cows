#ifndef RESULT_H
#define RESULT_H

#include "mainwindow.h"
#include "mainmenu.h"
#include <QDialog>

class MainWindow;

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

private:
    Ui::Result *ui;
    MainWindow *w;

public:
    explicit Result(int result,
                    MainWindow *w,
                    QWidget *parent = nullptr);
    ~Result();

private slots:
    void on_quit_clicked();
};

#endif // RESULT_H
