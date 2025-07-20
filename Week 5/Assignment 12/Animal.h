#pragma once
#include <string>
#include <vector>
using namespace std;

class Animal 
{
public:
    string name;
    bool hair, feathers, eggs, milk, airborne, aquatic, predator, toothed, backbone, breathes, venomous, fins;
    int legs;
    bool tail, domestic, catsize; // data only had 0/1 for small/large, change catsize to int if additional sizes
    int classType;

    static Animal fromCSV(const string& line);
    void display(const vector<string>& classNames) const;
    vector<string> loadClassNames(const string& filename);
};

