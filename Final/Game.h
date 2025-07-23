#pragma once
#include "Area.h"
#include "Player.h"

Area* generateArea(int row, int col);
void gameLoop(Area* island[7][7], Player& player);