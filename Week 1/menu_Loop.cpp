#include <iostream>
using namespace std;

int main() 
{
    int choice;
    int total = 0;

    while (true) 
	{
	    cout << "Menu:\n";
	    cout << "1. Add to Total\n";
	    cout << "2. View Total\n";
	    cout << "3. Exit\n";
	    cout << "Choose an option: ";
	    cin >> choice;

	    switch (choice) 
		{
        	case 1:
            		cout << "Added to total!\n";
	    		++total;
            		break;
        	case 2:
            		cout << "Total is: " << total << endl;
            		break;
        	case 3:
            		cout << "Exiting...\n";
            		return 0;
        	default:
            		cout << "Invalid option.\n";
    	}

    }
}