#include <string>
#include <vector>
#include "dice.h"

class Player {
public:

    Player(const std::string name, int score, std::vector<Dice> dice);

    int rollDice();
    int getTotalValue();
    int getScore();
    void increaseScore();
    void addDie(int sides);
    std::string getName();
    
private:
    std::string name;
    int score;
    std::vector<Dice> dice;

};


