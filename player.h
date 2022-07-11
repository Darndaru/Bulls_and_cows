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


public:
    Player(QString);

    void set_guessed_number(QString);
    QString get_guessed_number();

    int get_bulls();
    int get_cows();
    bool isOppNumberInput();


private:
    void set_digits_of_guessed_number();
    bool same_symbols_for_indexes(int, int);

};

#endif // PLAYER_H
