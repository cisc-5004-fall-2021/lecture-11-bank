#include <iostream>
#include "bank.h"

using namespace std;

int main() {
    Account *accounts[1000];

    accounts[0] = new BrassAccount {"Matt", 1234, 200};
    accounts[1] = new BrassPlusAccount {"Alice", 2345, 300, 0.01};

    cout << "Matt's account:" << endl;
    accounts[0]->print();
    cout << "Depositing $10 in Matt's account:" << endl;
    accounts[0]->deposit(10);
    accounts[0]->print();
    cout << "Withdrawing $300 from Matt's account:" << endl;
    accounts[0]->withdraw(300);
    accounts[0]->print();
    cout << endl << endl;

    cout << "Alice's account:" << endl;
    accounts[1]->print();
    cout << "Depositing $10 in Alice's account:" << endl;
    accounts[1]->deposit(10);
    accounts[1]->print();
    cout << "Withdrawing $500 from Alice's account:" << endl;
    accounts[1]->withdraw(500);
    accounts[1]->print();
    cout << endl << endl;
}