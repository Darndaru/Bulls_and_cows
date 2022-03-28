#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {

private:
    QString number;
    int number_i;
    QString checking_number;
    int checking_number_i;

public:
    Player();

    void set_number(QString number);
    QString get_number();

    int get_bulls_for(QString checking_number);
    int get_cows_for(QString checking_number);
    bool check_cow();
    bool checked_as_bull();
};

#endif // PLAYER_H
