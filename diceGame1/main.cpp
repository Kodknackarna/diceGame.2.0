#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include <string>
#include "simpleDiceGame.h"


int main() {

    srand(time(0)); // Initialisera slumptalsgeneratorn med nuvarande tid
    //testkommentar
    //Dice dice(6, 0);

    //dice.roll();

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
   
    ////Player player1("Adam", 0, diceVector);
    ////Player player2("Youssef", 0, diceVector);


    //std::cout << "Player 1, first roll with 1 die: " << player1.rollDice() << std::endl;
    //std::cout << "Player 2, first roll with 1 die: " << player2.rollDice() << std::endl;

    //player1.addDie(6);
    //player2.addDie(6);

    //player1.rollDice();
    //player2.rollDice();

    //std::cout << "Player 1, second roll with 2 dice: " << player1.getTotalValue() << std::endl;
    //std::cout << "Player 2, second roll with 2 dice: " << player2.getTotalValue() << std::endl;

    //player1.increaseScore();

    //std::cout << player1.getScore() << std::endl;

    //player1.increaseScore();

    //std::cout << player1.getScore() << std::endl;

    return 0;
}