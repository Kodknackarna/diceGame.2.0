#include <vector>
#include <iostream>
//#include "player.h"


class SimpleDiceGame {
public:
	SimpleDiceGame();
	

	void startGame(std::vector<Player>& players,
		std::vector<Dice> diceVector);

	void takeTurn(std::vector<Player>& players);
};


