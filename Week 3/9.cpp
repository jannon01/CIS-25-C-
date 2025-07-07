#include <iostream>
#include <string>
using namespace std;

class ITEM // holds name and amount
{
public:
    string name;
    int quantity;

    void display() 
    {
        cout << "Item: " << name << ", Quantity: " << quantity << endl;
    }
};

void searchItem(ITEM inventory[], int size, const string& searchName) // check if item in system and show to user
{ // 'const string&' rather than 'string' to reference input rather than storing in memory
    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (inventory[i].name == searchName) 
        {
            cout << "Found: " << inventory[i].name << " - Quantity: " << inventory[i].quantity << endl;
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Item not found in inventory." << endl;
    }
}

int main() // create a inventory array, have user fill, show list / ask user to search for an item
{
    const int SIZE = 6; // only need to change here for array size
    ITEM inventory[SIZE];

    // loop for user to input items and amounts
    for (int i = 0; i < SIZE; i++) 
    {
        cout << "Enter name for item " << (i + 1) << ": ";
        cin >> ws; // discard any leading whitespace / get line for sneaky user input
        getline(cin, inventory[i].name);

        cout << "Enter quantity for " << inventory[i].name << ": ";
        cin >> inventory[i].quantity;
    }

    // loop items array to output to console
    cout << "\nInventory List:\n";
    for (int i = 0; i < SIZE; i++) 
    {
        inventory[i].display();
    }

    // search for an item
    string searchName;
    cout << "\nEnter item name to search: ";
    cin >> ws; // discard any leading whitespace / get line for sneaky user input
    getline(cin, searchName);
    searchItem(inventory, SIZE, searchName);

    return 0;
}