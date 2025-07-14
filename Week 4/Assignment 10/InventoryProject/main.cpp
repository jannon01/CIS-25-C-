//Code Example(main.cpp)
//main initializes class into objects and uses fuctions

#include <iostream>
#include "ITEM.h"
#include "ITEM.cpp"


using namespace std;

int main() 
{
    ITEM item1("Notebook", 10);
    ITEM item2("Pencil", 50);

    item1.display();
    item2.display();

    // test function, issue 1 notebook and 2 pencil for test
    cout << "1 Student enrolled!\n";
    item1.amountDecrease(); 
    item2.amountDecrease();
    item2.amountDecrease();

    item1.display();
    item2.display();

    return 0;
}
