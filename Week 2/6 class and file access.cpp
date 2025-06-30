#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
 
class ITEM // class with functions to save and load an item and an amount
{ 
public: 
    string name; 
    int quantity;

    void loadFromFile() 
    { 
        ifstream in("items.txt"); 
        if (in.is_open()) // open, output each line, close
        { 
            string line; 
            cout << "\nCurrent contents of items.txt:\n";
            while (getline(in, line)) 
            { 
                cout << line << endl; 
            } 
            in.close(); 
        } 
        else 
        { 
            cout << "Unable to open file for reading." << endl; 
        } 
    }

    void saveToFile() 
    { 
        ofstream out("items.txt", ios::app); // open in append mode to add user input to list, close
        if (out.is_open()) 
        { 
            out << name << "," << quantity << endl; 
            out.close(); 
            cout << "Item saved to file." << endl; 
        } 
        else 
        { 
            cout << "Unable to open file for writing." << endl; 
        } 
    }
}; 

int main() // display list from file, ask for input, save to file
{ 
    ITEM items;
    items.loadFromFile();

    cout << "Enter item name to add to items.txt: ";
    getline(cin, items.name); // getline to allow abstract entries

    cout << "Enter quantity: ";
    cin >> items.quantity;

    items.saveToFile();
    
    return 0; 
}
