#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {

private:
    QString number;


public:
    Player();

    void set_number(QString number);
    QString get_number();
};

#endif // PLAYER_H
