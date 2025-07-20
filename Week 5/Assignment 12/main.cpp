#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Animal.h"
#include "Animal.cpp"
using namespace std;

int main() 
{
    vector<Animal> animals;
    vector<string> classNames = loadClassNames("class.csv");

    ifstream file("zoo.csv"); 
    if (!file) // safety check for opening file
    {
        cerr << "Failed to open zoo.csv\n";
        return 1;
    }

    string line;
    getline(file, line); // skip the header line

    int lineCount = 0; // only loading 10 rows for assignment, remove '&& lineCount < 10' to load full file
    while (getline(file, line) && lineCount < 10) 
    {
        Animal animal = Animal::fromCSV(line);
        animals.push_back(animal);
        lineCount++;
    }

    cout << "Total Animals Loaded: " << animals.size() << "\n\n";

    for (const auto& animal : animals) {
        animal.display(classNames);
    }

    return 0;
}