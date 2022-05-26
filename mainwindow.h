#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QString>
#include <rules.h>
#include <player.h>
#include <exception>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Number {
    QString number;

    bool is_4_digit() {
        if (number.length() != 4)
            return false;

        for (QChar symbol : number)
            if (!symbol.isDigit())
                return false;
        return true;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_input_chosen_number_button_clicked();
    void game_rules();

private:
    Ui::MainWindow *ui;

    Number input;
    Player* player;
    Player* pc;

    void get_input();
    void clear_input();
    void block_input();
    void show_number_to_user();
    void input_chosen_number_button_close();
    void repeat_input();

    void show_table_heads();
};
#endif // MAINWINDOW_H
