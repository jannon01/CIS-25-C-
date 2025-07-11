#pragma once
#include <iostream>
#include <string>
using namespace std;

class SHIRT // private store, public return and display.. each type, color, and if clean
{
private:
    string type;
    string color;
    bool clean;

public:
    SHIRT(string type, string color, bool clean) : type(type), color(color), clean(clean) {}

    string getType() const { return type; }
    string getColor() const { return color; }
    bool isClean() const { return clean; }

    void setClean(bool status) { clean = status; }

    void display() const 
    {
        cout << "Type: " << type << ", Color: " << color << ", Clean: " << (clean ? "Yes" : "No") << endl;
    }
};