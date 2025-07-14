//Source Files (.cpp)
//Used to define (implement) the functions and methods declared in the header file.

// class->function(variables){definitions and work}

#include <iostream>
#include "ITEM.h"

ITEM::ITEM() 
{
    name = "Unknown";
    quantity = 0;
}

ITEM::ITEM(string itemName, int itemQty) 
{
    name = itemName;
    quantity = itemQty;
}

void ITEM::display() 
{
    cout << "Item: " << name << ", Quantity: " << quantity << endl;
}

void ITEM::amountDecrease()
{
    quantity--;
}