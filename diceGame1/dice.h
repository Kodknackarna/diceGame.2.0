#include <string>


class Dice {
public:
    Dice(int sides, int currentValue);

    int roll();
    int getValue();


private:
    int sides;
    int currentValue;

};

