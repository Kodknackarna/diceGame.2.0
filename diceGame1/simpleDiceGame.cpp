#include <iostream>
#include <vector>
#include "player.h"
#include "simpleDiceGame.h"
#include <string>

SimpleDiceGame::SimpleDiceGame() {

}




void SimpleDiceGame::startGame(std::vector <Player*>& players, std::vector<Dice> diceVector) {

	int numPlayers;
	std::string playerName;

	std::cout << "Enter the number of players: ";
	std::cin >> numPlayers;

	for (int i = 0; i < numPlayers; ++i) {
		std::cout << "Enter name for Player " << i + 1 <<
			": ";
		std::cin >> playerName;
		players.push_back(new Player(playerName, 0, diceVector));
	}

    

};

void SimpleDiceGame::takeTurn(std::vector<Player*>& players) {

    int highestValue = 0;

    for (auto& player : players) {
        int roll = player->rollDice();
        std::cout << player->getName() << " " << roll << std::endl;
        if (roll > highestValue) {
            highestValue = roll;
        }
    };

    for (auto& player : players) {
        if (player->getTotalValue() == highestValue) {
            player->increaseScore();
        }
        else {
            player->addDie(6);
        }
        std::cout << player->getName() << " has a score of: " << player->getScore() << "\n" << std::endl;
    }

};

std::vector<std::string> SimpleDiceGame::getWinners(std::vector<Player*>& players, int winScore) {
    std::vector<std::string> winners;
    
    for (auto& player : players) {
        if (player->getScore() >= winScore) {
            winners.push_back(player->getName());
        };

    }
    return winners;
}
