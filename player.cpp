#include "player.h"

Player::Player() {

}

void Player::set_number(QString number) {
    this->number = number;
}

QString Player::get_number() {
    return number;
}

int Player::get_bulls_for(QString number) {
    checking_number = number;
    int num_of_bulls = 0;

    for (int i = 0; i < 4; i++)
        if (number[i] == checking_number[i])
            num_of_bulls++;

    return num_of_bulls;
}

int Player::get_cows_for(QString number) {
    checking_number = number;
    int num_of_cows = 0;

    for (int checking_number_i = 0;
             checking_number_i < 4;
             checking_number_i++)
        if (check_cow())
            num_of_cows++;

    return num_of_cows;
}

bool Player::check_cow() {
    for (int number_i = 0; number_i < 4; number_i++)
        if (!checked_as_bull())
            if (number[number_i] ==
                    checking_number[checking_number_i])
                return true;
    return false;

}

bool Player::checked_as_bull() {
    if (number_i == checking_number_i)
        return true;
    return false;
}
