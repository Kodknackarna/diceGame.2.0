#include <iostream>
#include <vector>
#include "player.h"
#include "simpleDiceGame.h"

SimpleDiceGame::SimpleDiceGame() {

}




void SimpleDiceGame::startGame(std::vector <Player>& players, std::vector<Dice> diceVector) {

	int numPlayers;
	std::string playerName;

	std::cout << "Enter the number of players: ";
	std::cin >> numPlayers;

	for (int i = 0; i < numPlayers; ++i) {
		std::cout << "Enter name for Player " << i + 1 <<
			": ";
		std::cin >> playerName;
		players.push_back(Player(playerName, 0, diceVector));
	}

};
void SimpleDiceGame::takeTurn(std::vector<Player>& players) {

    int highestValue = 0;

    for (auto& player : players) {
        int roll = player.rollDice();
        std::cout << player.name << " " << roll << std::endl;
        if (roll > highestValue) {
            highestValue = roll;
        }
    };

    for (auto& player : players) {
        if (player.getTotalValue() == highestValue) {
            player.increaseScore();
        }
        else {
            player.addDie(6);
        }
        std::cout << player.name << " has a score of: " << player.getScore() << "\n" << std::endl;
    }

};

