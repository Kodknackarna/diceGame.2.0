#include "dice.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

Dice::Dice(int sides, int currentValue) : sides(sides), currentValue(currentValue) {}

int Dice::roll() {
    return
        currentValue = (rand() % sides) + 1;
};

int Dice::getValue() {
    return currentValue;
};