#include "Player.h"

void Player::move(char dir) // move unless at edge of island, then pass time
{
    switch (dir) 
    {
        case 'n': if (y > 0) y--; break;
        case 's': if (y < 6) y++; break;
        case 'w': if (x > 0) x--; break;
        case 'e': if (x < 6) x++; break;
    }
    passTime();
}

bool Player::isGameOver() const // trigger if hunger meter runs out or player survives 30 days
{
    return hunger <= 0 || days >= 30;
}

void Player::passTime()  // progress day by 1/3 and reduce hunger meter
{
    dayProgress += 0.33f;
    hunger -= 1;
    if (dayProgress >= 1.0f) 
    {
        days++;
        dayProgress = 0;
    }
}