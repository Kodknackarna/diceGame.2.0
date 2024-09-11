
#include "player.h"
#include <string>
#include <vector>

Player::Player(const std::string name, int score, std::vector<Dice> dice)
    : name(name), score(score), dice(dice) {}

int Player::rollDice() {
    int totalValue = 0;

    for (auto& die : dice) {
        totalValue += die.roll();
    }
    return totalValue;
};

void Player::addDie(int sides) {
    dice.push_back(Dice(sides, 0));
};

int Player::getTotalValue() {
    int totalValue = 0;

    for (auto& die : dice) {
        totalValue += die.getValue();
    }

    return totalValue;
};

int Player::getScore() {
    return score;
}

void Player::increaseScore() {
    score++;
};
