#include "player.h"

Player::Player(QString number) {
    hidden_number = number;
}

QString Player::get_hidden_number() {
    return hidden_number;
}

void Player::set_guessed_number(QString number) {
    guessed_number = number;
    set_digits_of_guessed_number();
}

void Player::set_digits_of_guessed_number() {
    digits_of_guessed_number.resize(0);
    for (auto symbol : guessed_number)
        digits_of_guessed_number.push_back(symbol);
}

QString Player::get_guessed_number() {
    return guessed_number;
}

int Player::get_bulls() {
    int counter = 0;
    for (int i = 0; i < num_of_digits; i++)
        if (same_symbols_for_indexes(i, i))
            counter++;
    return counter;
}

int Player::get_cows() {
    int counter = 0;
    for (auto real_symbol : opponent_number)
        for (auto guessed_symbol : digits_of_guessed_number)
            if (real_symbol == guessed_symbol) {
                counter++;
                break;
            }
    counter -= bulls_for_guessed_number;
    return counter;
}


bool  Player::same_symbols_for_indexes(int real_num_ind,
                                       int guessed_num_ind) {
    if (opponent_number[real_num_ind] ==
            guessed_number[guessed_num_ind])
        return true;
    return false;
}
