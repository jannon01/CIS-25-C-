#include "SaveSystem.h"
#include "Biomes.h"
#include <iostream>

bool saveGame(Area* island[7][7], const Player& player, const std::string& filename) 
{
    std::ofstream out(filename);
    if (!out) return false;

    // save player data
    out << player.x << " " << player.y << " " << player.hunger << " " << player.days << " " << player.dayProgress << "\n";

    // save island data
    for (int y = 0; y < 7; ++y) 
    {
        for (int x = 0; x < 7; ++x) {
            std::string type = island[y][x]->getType();
            out << type << " ";

            if (type == "Ocean")
            {
                // check each ocean to save amount of fish remaining
                const Ocean* ocean = dynamic_cast<const Ocean*>(island[y][x]);
                out << ocean->getFishCount();
            }
            out << " ";
        }
        out << "\n";
    }
    return true;
}

bool loadGame(Area* island[7][7], Player& player, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;

    // load player data
    in >> player.x >> player.y >> player.hunger >> player.days >> player.dayProgress;

    // load island data
    for (int y = 0; y < 7; ++y) {
        for (int x = 0; x < 7; ++x) {
            std::string type;
            in >> type;

            // load in fish amounts and set various x,y biomes
            if (type == "Ocean") {
                int fish;
                in >> fish;
                Ocean* ocean = new Ocean();
                ocean->setFishCount(fish);
                island[y][x] = ocean;
            } else if (type == "Sand") {
                island[y][x] = new Sand();
            } else if (type == "Jungle") {
                island[y][x] = new Jungle();
            } else if (type == "Clearing") {
                island[y][x] = new Clearing();
            }
        }
    }

    return true;
}