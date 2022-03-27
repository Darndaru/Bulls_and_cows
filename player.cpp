#include "player.h"

Player::Player() {

}

void Player::set_number(QString number) {
    this->number = number;
}

QString Player::get_number() {
    return number;
}
