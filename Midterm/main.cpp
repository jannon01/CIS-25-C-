#include <iostream>
#include <fstream>
#include "OutfitManager.h"
#include "Shirt.h"
#include "Pants.h"
using namespace std;

int main() // initialze manager to handle actions, run menu for user
{
    OUTFITMANAGER manager;
    int choice;

    // an initial example of some clothing, remove for real-world use
    manager.addShirt(SHIRT("T-shirt", "Blue", true));
    manager.addShirt(SHIRT("Polo", "Red", false));
    manager.addShirt(SHIRT("Tank top", "Yellow", false));
    manager.addPants(PANTS("Jeans", "Blue", true));
    manager.addPants(PANTS("Shorts", "Red", false));
    manager.addPants(PANTS("Sweatpants", "Yellow", true));

    do 
    {
        cout << "\n--- Outfit Manager Menu ---\n";
        cout << "1. Display Closet\n";
        cout << "2. Add Clothing\n";
        cout << "3. Do Laundry\n";
        cout << "4. Save to closet.txt\n";
        cout << "5. Load from closet.txt\n";
        cout << "6. Search Outfit by Color\n";
        cout << "7. Random Clean Outfit\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            manager.displayCloset();
        } 
        else if (choice == 2) 
        {
            manager.userAddClothing();
        } 
        else if (choice == 3) 
        {
            manager.doLaundry();
        } 
        else if (choice == 4) 
        {
            manager.saveToFile("closet.txt");
        } 
        else if (choice == 5) 
        {
            manager.loadFromFile("closet.txt");
        }
        else if (choice == 6)
        {
            string color;
            cout << "\nEnter color to search for matching outfit: ";
            cin >> color;
            manager.searchOutfitByColor(color);
        }
        else if (choice == 7)
        {
            manager.randomizeOutfit();
        }

    } while (choice != 0);

    return 0;
}