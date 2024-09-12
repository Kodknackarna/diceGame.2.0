#include <vector>
#include <iostream>
#include <string>


class SimpleDiceGame {
public:
	SimpleDiceGame();
	

	void startGame(std::vector<Player*>& players,
		std::vector<Dice> diceVector);

	void takeTurn(std::vector<Player*>& players);

	std::vector<std::string> getWinners(std::vector<Player*>& players, int winScore);
};


