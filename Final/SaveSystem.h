#pragma once
#include "Area.h"
#include "Player.h"
#include <fstream>
#include <string>

//handles saving and loading game state to/from a file

bool saveGame(Area* island[7][7], const Player& player, const std::string& filename);
bool loadGame(Area* island[7][7], Player& player, const std::string& filename);