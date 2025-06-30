#include <iostream>
using namespace std;

// base class
class Item 
{
public:
    string name;
    int quantity;

    Item(string n, int q) : name(n), quantity(q) {}

    virtual void display() = 0; // pure virtual function
};

// Perishable items class
class Perishable : public Item 
{
public:
    Perishable(string n, int q) : Item(n, q) {} // pass on name and quanitity through abstraction

    void display() override // overrides virtual 
    {
        cout << name << " (Perishable), Qty: " << quantity << endl;
    }
};

// non-Perishable items class
class NonPerishable : public Item 
{
public:
    NonPerishable(string n, int q) : Item(n, q) {}

    void display() override 
    {
        cout << name << " (Non-Perishable), Qty: " << quantity << endl;
    }
};


int main() // initiate, prompt to add item type, take in name and quantity, pass on through virtual command
{
    int choice;
    string itemName;
    int itemQty;

    cout << "Enter item type:\n";
    cout << "1. Perishable\n";
    cout << "2. Non-Perishable\n";
    cout << "Choice (1 or 2): ";
    cin >> choice;

    // check for valid choice, if error mark as perishable to prevent spoilage
    if (choice != 1 && choice != 2) {
        cout << "Invalid choice. Setting to Perishable for safety." << endl;
        choice = 1;
    }

    cout << "Enter item name: ";
    cin >> ws; // clear newline left in buffer by cin, ignore error-flag on next line
    getline(cin, itemName);

    cout << "Enter quantity: ";
    cin >> itemQty;
    
    if (itemQty < 0) 
    {
    cout << "Invalid quantity. Setting to 0.\n";
    itemQty = 0;
    }

    Item* item = nullptr;

    if (choice == 1) {
        item = new Perishable(itemName, itemQty);
    } else {
        item = new NonPerishable(itemName, itemQty);
    }

    cout << "\nItem Details:\n";
    item->display();

    delete item; // clean up
    return 0;
}
