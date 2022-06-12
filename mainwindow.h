#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QVBoxLayout>

#include <rules.h>
#include <myserver.h>
#include <myclient.h>
#include <player.h>

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

struct ResultOfTry {
    QLabel *number;
    QLabel *bulls;
    QLabel *cows;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVector <ResultOfTry> user_results;
    QVector <ResultOfTry> opp_results;

    Number input;
    Player* user = nullptr;
    Player* opp = nullptr;
    bool isServer;
    int u_num_of_attempts;
    int o_num_of_attempts;

public:
    MyServer *server = nullptr;
    MyClient *client = nullptr;

private:
    void getInput();
    void clearInput();
    void blockInput();
    void unlockInput();
    void repeatInput();

    void isItServer();
    void sendNumber(QString);

    void showNumberToUser();
    void showUserResults();
    void showOppResults();
    void showResults(QString, Player*);

    bool draw_condition();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showTableHeads();

private slots:
    void on_inputChosenNumber_clicked();
    void gameRules();

public slots:
    void slotGetOppNumber();
    void slotConnectionEstablished();
};
#endif // MAINWINDOW_H
