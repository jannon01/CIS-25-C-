//Header Files (.h)
//Used to declare class definitions and function prototypes.

// private holders for the object that stay const unless directly changed
// public functions(variables) that can be called

#pragma once

#include <string>
using namespace std;

class ITEM 
{
private: 
    string name;
    int quantity;

public: 
    ITEM();
    ITEM(string itemName, int itemQty);
    void display();
    void amountDecrease();
};