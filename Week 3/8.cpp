#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for std::fixed and std::setprecision to keep balance rounded
using namespace std;

// BANKACCOUNT class manages balance and transaction recording
class BANKACCOUNT 
{
private:
    float balance; 

public:
    BANKACCOUNT() 
    {
        balance = 0.0;
    }

    void deposit(float amount) // handles depositing money to account
    {
        balance += amount;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, float cost) // checks for available funds and saves transaction or failure
    {
        if (cost > balance) 
        {
            cout << "Insufficient funds for " << item << endl;
            saveTransaction("Failed transaction - " + item, cost);
        } 
        else 
        {
            balance -= cost;
            cout << "Purchase complete" << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() // show user balance
    {
        cout << fixed << setprecision(2);
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(string type, float amount) // outputs transactions to txt doc
    {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) 
        {
            file << fixed << setprecision(2);
            file << type << ": $" << amount << endl;
            file.close();
        }
        else 
        {
            cerr << "Unable to open file for writing.\n";
        }
    }
};

int main() // run test of system, replace with user input for realworld
{
    BANKACCOUNT myAccount;

    myAccount.deposit(1000.00);
    myAccount.makePurchase("College fees", 694.50);
    myAccount.makePurchase("Housing", 1125.00); //transaction should fail to demonstrate else case
    myAccount.makePurchase("Books", 195.00);
    myAccount.displayBalance();

    return 0;
}