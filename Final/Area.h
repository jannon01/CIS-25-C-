#pragma once
#include "Player.h"
#include <string>
#include <iostream>

class Area // Base class for all island areas
{
protected:
    std::string description;
public:
    virtual void describe() const = 0;
    virtual std::string getType() const = 0;
    virtual void performAction(Player& player) = 0;
    virtual ~Area() {}
};

