#pragma once
#include "Area.h"
#include <string>

class Ocean : public Area 
{
private:
    int fishCount;
public:
    int getFishCount() const;
    void setFishCount(int);
    Ocean();
    void describe() const override;
    std::string getType() const override;
    void performAction(Player& player) override;
};

class Sand : public Area 
{
public:
    Sand();
    void describe() const override;
    std::string getType() const override;
    void performAction(Player& player) override; // virtual atm, no actions on sand yet
};

class Jungle : public Area 
{
public:
    Jungle();
    void describe() const override;
    std::string getType() const override;
    void performAction(Player& player) override;
};

class Clearing : public Area 
{
public:
    Clearing();
    void describe() const override;
    std::string getType() const override;
    void performAction(Player& player) override;
};