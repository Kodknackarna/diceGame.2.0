#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include <string>
#include "simpleDiceGame.h"


int main() {

    srand(time(0)); // Initialisera slumptalsgeneratorn med nuvarande tid

    std::vector<Dice> diceVector = { Dice(6, 0) };
    std::vector<Player*> players;

    SimpleDiceGame game;

    game.startGame(players, diceVector);
    int winScore; // choise a max score for the game
    std::cout << "Enter the max-score for the dice game: " << std::endl;
    std::cin >> winScore;


    bool done = false;
    while (!done) {
        game.takeTurn(players);

        for (auto& player : players) {
            if (player->getScore() >= winScore) {
                done = true;
            }
        }
    }

    std::vector<std::string> winners = game.getWinners(players, winScore);
    if (winners.size() > 10) {
        std::cout << "The winners are: " << std::endl;
    }
    else {
        std::cout << "The winner is: " << std::endl;
    };

    for (const auto& winner : winners) {
        std::cout << winner << std::endl;

    }
    for (auto player : players) {
        delete player;
    }

    return 0;
}