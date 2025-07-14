#include "Employee.h"
#include "User.h"
#include "InventoryManager.h"
#include "Employee.cpp"
#include "User.cpp"
#include "InventoryManager.cpp"

int main() 
{
    InventoryManager mgr;
    mgr.accessLevel(); // Should print: Full Inventory Management Access
    //testing others
    std::cout << "\nTesting other user levels" << std::endl;
    Employee emp; 
    emp.accessLevel();

    User User;
    User.accessLevel();
    return 0;
}