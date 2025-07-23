#pragma once
#include <string>

struct Player 
// change to class and refactor in future with setters/getters and a inventory to carry food / crafting materials
{
    int x = 3; // starting position x,y
    int y = 3;
    int hunger = 12;
    float dayProgress = 0; // 3 actions per day
    int days = 0;

    void move(char dir);
    bool isGameOver() const;
    void passTime();
};