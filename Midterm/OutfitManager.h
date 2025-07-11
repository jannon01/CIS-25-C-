#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include "Shirt.h"
#include "Pants.h"
using namespace std;

// adds clothing in a dynamic array for user to add in their entire wardrobe, displays list, does
// searches for a color-matching outfit or a random clean outfit, a laundry function to set all to clean,
// and a save/load system that can easily be mass-updated through the txt file

class OUTFITMANAGER
{
private:
    vector<SHIRT> shirts;
    vector<PANTS> pants;

public:
    void addShirt(const SHIRT& shirt) 
    {
        shirts.push_back(shirt);
    }

    void addPants(const PANTS& pant) 
    {
        pants.push_back(pant);
    }

    void userAddClothing()
    {
        string type, color, classType;
        char cleanInput;
        bool clean;

        cout << "\nIs this a shirt or pants? ";
        cin >> classType;

        cout << "Enter type (e.g. T-shirt, Jeans): ";
        cin.ignore();
        getline(cin, type);

        cout << "Enter color: ";
        getline(cin, color);

        cout << "Is it clean? (y/n): ";
        cin >> cleanInput;
        clean = (cleanInput == 'y' || cleanInput == 'Y');

        if (classType == "shirt" || classType == "Shirt")
            addShirt(SHIRT(type, color, clean));
        else if (classType == "pants" || classType == "Pants")
            addPants(PANTS(type, color, clean));
        else
            cout << "Invalid clothing type.\n";
    }

    void displayCloset() const 
    {
        cout << "\n---- Shirts ----" << endl;
        for (const auto& shirt : shirts) 
        {
            shirt.display();
        }

        cout << "---- Pants ----" << endl;
        for (const auto& pant : pants) 
        {
            pant.display();
        }
    }

    void searchOutfitByColor(const string& color) const 
    {
        cout << "\nMatching outfits for color '" << color << "':" << endl;

        for (const auto& shirt : shirts) 
        {
            for (const auto& pant : pants) 
            {
                if (shirt.getColor() == color && pant.getColor() == color) 
                {
                    cout << "Outfit: ";
                    shirt.display();
                    pant.display();
                    cout << endl;
                }
            }
        }
    }

   void randomizeOutfit() const 
    {
    vector<SHIRT> cleanShirts;
    vector<PANTS> cleanPants;

    // filter only clean shirts and pants
    for (const auto& shirt : shirts)
        if (shirt.isClean()) cleanShirts.push_back(shirt);
    for (const auto& pant : pants)
        if (pant.isClean()) cleanPants.push_back(pant);

    // if no clean combinations exist
    if (cleanShirts.empty() || cleanPants.empty()) 
        {
        cout << "No clean outfit available.\n";
        return;
        }

    // pick random clean items
    srand(static_cast<unsigned int>(time(nullptr)));
    int shirtIndex = rand() % cleanShirts.size();
    int pantIndex = rand() % cleanPants.size();

    cout << "\nRandom Clean Outfit:\n";
    cleanShirts[shirtIndex].display();
    cleanPants[pantIndex].display();
    }
    
    void doLaundry() 
    {
    for (auto& shirt : shirts) 
        {
        shirt.setClean(true);
        }

    for (auto& pant : pants) 
        {
        pant.setClean(true);
        }

        cout << "\nLaundry Day! All clothes are now clean." << endl;
    }

    void saveToFile(const string& filename) const 
    {
        ofstream out(filename);
        if (!out) 
        {
            cout << "\nError opening file for writing.\n";
            return;
        }

        for (const auto& s : shirts)
            out << "Shirt," << s.getType() << "," << s.getColor() << "," << (s.isClean() ? "1" : "0") << endl;

        for (const auto& p : pants)
            out << "Pants," << p.getType() << "," << p.getColor() << "," << (p.isClean() ? "1" : "0") << endl;

        cout << "\nCloset saved to " << filename << ".\n";
    }

    void loadFromFile(const string& filename) 
    {
        ifstream in(filename);
        if (!in) 
        {
            cout << "\nError opening file for reading.\n";
            return;
        }

        shirts.clear();
        pants.clear();

        string line;
        while (getline(in, line)) 
        {
            stringstream ss(line);
            string itemType, type, color, cleanStr;
            getline(ss, itemType, ',');
            getline(ss, type, ',');
            getline(ss, color, ',');
            getline(ss, cleanStr);

            bool clean = (cleanStr == "1");

            if (itemType == "Shirt")
                shirts.push_back(SHIRT(type, color, clean));
            else if (itemType == "Pants")
                pants.push_back(PANTS(type, color, clean));
        }

        cout << "\nCloset loaded from " << filename << ".\n";
    }
};