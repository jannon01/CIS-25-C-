#include "Game.h"
#include "Biomes.h"
#include "Area.h"
#include "Player.h"
#include "SaveSystem.h"
#include "Game.cpp"
#include "Biomes.cpp"
#include "Player.cpp"
#include "SaveSystem.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Area* globalIsland[7][7]; // initialize pointer array for handling of island state for Biome/save management

int main() 
{
    srand(time(0)); // seed random number generator
    Player player; // initialize player and prompt to start or load

    std::cout << "Welcome to Desert Island Survival!\n";
    std::cout << "[n]ew game or [l]oad game? ";
    char choice;
    std::cin >> choice;

    if (choice == 'l') // attempt to load a saved game
    {
        if (!loadGame(globalIsland, player, "save.txt")) 
        {
            std::cout << "Failed to load save. Starting new game.\n";
            goto newgame;
        }
    } else { // fill in a new island with a random generation
        newgame:
        for (int y = 0; y < 7; ++y)
            for (int x = 0; x < 7; ++x)
                globalIsland[y][x] = generateArea(y, x);
    }

    gameLoop(globalIsland, player); // run game

    // after gameover, cleanup array
    for (int y = 0; y < 7; ++y)
        for (int x = 0; x < 7; ++x)
            delete globalIsland[y][x];
}