// initialize used databases
#include <iostream> 
#include <string> 
using namespace std;

// define stuct named item with a name and id
struct Item 
{ 
    int id; 
    string name;
}; 


// binary search function
int binary_Search(Item items[], int size, int search_Id) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
    int mid = (left + right) / 2;

        if (items[mid].id == search_Id) {
            return mid;
        } else if (items[mid].id < search_Id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // id not found
}

//main program
int main() 
{ 
    // create a new living array of items
    Item* items = new Item[4]; 
    // fill sorted array 
    items[0] = {001, "Coffee"}; 
    items[1] = {711, "Soap"}; 
    items[2] = {993, "Cupcake"};
    items[3] = {999, "Soup"}; 

    // display items
    for (int i = 0; i < 4; ++i) 
    { 
    cout << "Item ID: " << items[i].id  << ", Name: " << items[i].name  << std::endl; 
    } 
    
    // ask user for an ID to search
    int search_Id;
    cout << "\nConsult current list above, or enter an Item ID to search: ";
    cin >> search_Id;

    // perform binary search
    int result_Index = binary_Search(items, 4, search_Id);

    if (result_Index != -1) {
        cout << "Item found: " << items[result_Index].name << " (ID: " << items[result_Index].id << ")\n";
    } else {
        cout << "Item with ID " << search_Id << " not found.\n";
    }

    delete[] items; // kill memory usage
    return 0; 
}