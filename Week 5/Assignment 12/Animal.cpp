#include "Animal.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
using namespace std;

Animal Animal::fromCSV(const string& line) // translate each line into what attributes the animal has
{
    Animal a;
    stringstream ss(line);
    string token;

    getline(ss, a.name, ',');
    getline(ss, token, ','); a.hair = stoi(token);
    getline(ss, token, ','); a.feathers = stoi(token);
    getline(ss, token, ','); a.eggs = stoi(token);
    getline(ss, token, ','); a.milk = stoi(token);
    getline(ss, token, ','); a.airborne = stoi(token);
    getline(ss, token, ','); a.aquatic = stoi(token);
    getline(ss, token, ','); a.predator = stoi(token);
    getline(ss, token, ','); a.toothed = stoi(token);
    getline(ss, token, ','); a.backbone = stoi(token);
    getline(ss, token, ','); a.breathes = stoi(token);
    getline(ss, token, ','); a.venomous = stoi(token);
    getline(ss, token, ','); a.fins = stoi(token);
    getline(ss, token, ','); a.legs = stoi(token);
    getline(ss, token, ','); a.tail = stoi(token);
    getline(ss, token, ','); a.domestic = stoi(token);
    getline(ss, token, ','); a.catsize = stoi(token); 
    getline(ss, token, ','); a.classType = stoi(token);

    return a;
}

void Animal::display(const vector<string>& classNames) const // display attirbutes with proper descriptions
{
    cout << "-----------------------------------------------------\n";
    cout << "Animal Name     : " << name << "\n"
         << "Class Type      : " << classType;

    if (classType >= 1 && classType <= (int)classNames.size())
        cout << " (" << classNames[classType - 1] << ")";

    cout << "\n\n";
    cout << "Features:\n";

    if (hair)       cout << "  - Has Hair\n";
    if (feathers)   cout << "  - Has Feathers\n";
    if (eggs)       cout << "  - Lays Eggs\n";
    if (milk)       cout << "  - Produces Milk\n";
    if (airborne)   cout << "  - Can Fly\n";
    if (aquatic)    cout << "  - Is Aquatic\n";
    if (predator)   cout << "  - Is a Predator\n";
    if (toothed)    cout << "  - Has Teeth\n";
    if (backbone)   cout << "  - Has a Backbone\n";
    if (breathes)   cout << "  - Breathes\n";
    if (venomous)   cout << "  - Is Venomous\n";
    if (fins)       cout << "  - Has Fins\n";
    if (tail)       cout << "  - Has a Tail\n";
    if (domestic)   cout << "  - Is Domesticated\n";

    if (legs > 0)
        cout << "  - Legs: " << legs << "\n";

    if (catsize == 0)
        cout << "  - Size: Small\n";
    else if (catsize == 1)
        cout << "  - Size: Large\n";

    cout << "-----------------------------------------------------\n\n";
}

// load class type names from class.csv into a array
vector<string> loadClassNames(const string& filename) 
{
    vector<string> classNames;
    ifstream file(filename);
    string line;

    getline(file, line); // skip header

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ','); // class number
        getline(ss, token, ','); // skip total count in class
        getline(ss, token, ','); // class name
        classNames.push_back(token);
    }

    return classNames;
}