#include "Game.h"
#include "Biomes.h"
#include <iostream>
using namespace std;

Area* generateArea(int row, int col) 
// randomly create island, outer edges with oceans or sand, inner with jungle or clearing
{
    if (row == 0 || col == 0 || row == 6 || col == 6) 
    {
        return rand() % 2 ? static_cast<Area*>(new Ocean()) : static_cast<Area*>(new Sand());
    } else {
        return rand() % 2 ? static_cast<Area*>(new Jungle()) : static_cast<Area*>(new Clearing());
    }
}

void gameLoop(Area* island[7][7], Player& player) 
// main loop of displaying stats and allows player to move, describe area, or perform actions. 
{
    while (!player.isGameOver())
    {
        std::cout << "\nDay " << player.days << "  Hunger: [" << std::string(player.hunger, '#') << std::string(12 - player.hunger, '-') << "]\n";
        std::cout << "You are at (" << player.x << ", " << player.y << ")\n";
        std::cout << "Choose action: [n]orth [s]outh [e]ast [w]est [l]ook [a]ction\n> ";
        
        char action;
        cin >> action;
        if (action == 'l') 
        {
        island[player.y][player.x]->describe();
        } else if (action == 'a'){
        island[player.y][player.x]->performAction(player);
        } else {
        player.move(action);
        }  
    }

    // at game over, display final message
    if (player.hunger <= 0) 
    {
    std::cout << "\nYou have starved. Game Over.\n";
    } else {
    std::cout << "\n30 days have passed. You survived! Victory!\n";
    }
}