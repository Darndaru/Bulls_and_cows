#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QVector>

class Player
{
private:
    const int num_of_digits = 4;
    QString hidden_number;
    QString opponent_number;
    QString guessed_number;
    int bulls_for_guessed_number;
    int cows_for_guessed_number;

    QVector <QChar> digits_of_guessed_number;

    void set_digits_of_guessed_number();
    bool same_symbols_for_indexes(int, int);

public:
    Player(QString);

    QString get_hidden_number();
    void set_guessed_number(QString);
    QString get_guessed_number();

    int get_bulls();
    int get_cows();
};

#endif // PLAYER_H
