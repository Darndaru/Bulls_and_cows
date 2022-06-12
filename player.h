#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QVector>

class Player
{
private:
    const int num_of_digits = 4;
    QString opp_number = "";
    QString guessed_number;
    int bulls;
    int cows;

    QVector <QChar> digits_of_guessed_number;

    void set_digits_of_guessed_number();
    bool same_symbols_for_indexes(int, int);

public:
    Player(QString);
    void set_guessed_number(QString);
    QString get_guessed_number();
    void set_opp_number(QString);

    int get_bulls();
    int get_cows();
    bool isOppNumberInput();
};

#endif // PLAYER_H
