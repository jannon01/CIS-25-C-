#include "Biomes.h"
#include "SaveSystem.h"
#include "Area.h"
#include <iostream>
extern Area* globalIsland[7][7]; // handles island state for save

Sand::Sand()  // basic area, with no special actions at the moment
{
    description = "Hot sand scorches your feet. Maybe something is buried here.";
}

void Sand::describe() const { std::cout << description << std::endl; }
std::string Sand::getType() const { return "Sand"; }

void Sand::performAction(Player& player) {
    std::cout << "You idly search the beach, but there is nothing to do here.\n";
    player.passTime();
}


Ocean::Ocean() // holds random amount of fish and a description
{
    fishCount = 2 + rand() % 9; // 2 to 10 fish
    description = "You see the endless ocean. Swimming out is certain death.";
}

void Ocean::setFishCount(int f) { fishCount = f; }
int Ocean::getFishCount() const { return fishCount; }
std::string Ocean::getType() const { return "Ocean";}

void Ocean::describe() const // override if fish run out
{
    std::cout << (fishCount > 0 ? description : "The ocean looks empty of life.") << std::endl;
}

void Ocean::performAction(Player& player) 
{
    if (fishCount <= 0) 
    {
        std::cout << "You try to fish, but the waters are empty.\n";
    } else if ((rand() % 100) < 70) {
        std::cout << "You catch a fish and eat it.\n";
        player.hunger = std::min(player.hunger + 4, 12);
        fishCount--;
    } else {
        std::cout << "You fail to catch anything.\n";
    }
    
    player.passTime();
}


Jungle::Jungle() // allows to search for food
{
    description = "Dense jungle surrounds you. You hear distant wildlife.";
}

void Jungle::describe() const { std::cout << description << std::endl; }
std::string Jungle::getType() const { return "Jungle"; }

void Jungle::performAction(Player& player) { // 50% chance to find food
    if ((rand() % 100) < 50) {
        std::cout << "You find some berries and eat them.\n";
        player.hunger = std::min(player.hunger + 4, 12); // fills 4 hunger points
    } else {
        std::cout << "You find nothing edible.\n";
    }
    player.passTime();
}


Clearing::Clearing() // save or pass time.. area for building a base in future
{
    description = "An open clearing with some sunlight. A good place to rest.";
}

void Clearing::describe() const { std::cout << description << std::endl; }
std::string Clearing::getType() const { return "Clearing"; }

void Clearing::performAction(Player& player) 
{
    std::cout << "You can choose to [s]ave the game or [r]est.\n> ";
    std::string input;
    std::getline(std::cin >> std::ws, input);
    char choice = tolower(input[0]);

    if (choice == 's') 
    {
    if (saveGame(globalIsland, player, "save.txt")) 
        {
        std::cout << "Game saved.\n";
        } else {
        std::cout << "Failed to save.\n";
        }
    } else {
    std::cout << "You rest for a while.\n";
    player.passTime();
    }
}