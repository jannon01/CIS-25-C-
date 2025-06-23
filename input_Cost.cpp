#include <iostream> 
using namespace std; 

int main() 
{
    string food_Name; 
    int amount; 
    float price; 

    cout << "Enter type of produce: "; 
    cin >> food_Name; 
    cout << "Enter amount: "; 
    cin >> amount; 
    cout << "Enter price: "; 
    cin >> price; 

    cout << "Total cost for " << food_Name << ": $" << (amount * price) << endl;
    cout << "If you had $5 you could purchase " << (int)(5 / price) << " " << food_Name << "(s)\n";

    return 0; 
}