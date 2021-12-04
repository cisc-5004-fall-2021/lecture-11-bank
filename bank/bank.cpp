#include "bank.h"
#include <iostream>

// Base class constructor: defining this here means that all descendents
// of Account must have at least a name, ID, and initial balance.
Account::Account(string name, int id, double balance) {
    this->name = name;
    this->id = id;
    this->balance = balance;
}

// BrassAccount has nothing to add to the Account constructor.
// We define an empty constructor and use a member initializer list
// to invoke the Account constructor
BrassAccount::BrassAccount(string name, int id, double balance) 
    : Account(name, id, balance) {}

void BrassAccount::print() {
    cout << "Account for " << this->name << " #" << this->id << " $" << this->balance << endl;
}

void BrassAccount::deposit(double amt) {
    this->balance += amt;
}

bool BrassAccount::withdraw(double amt) {
    if (this->balance - amt >= 0.0) {
        this->balance -= amt;
        return true;
    } else {
        cout << "Not enough balance" << endl;
        return false;
    }
}

// The BrassPlusAccount constructor has more to do than the
// BrassAccount constructor. Here, we invoke the BrassAccount
// constructor in a member initialiation list, then initialize
// values for overdraftPenalty and overdraftBalance.
BrassPlusAccount::BrassPlusAccount(string name, int id, double balance, double overdraftPenalty)
    : BrassAccount(name, id, balance)
{
    this->overdraftPenalty = overdraftPenalty;
    this->overdraftBalance = 0.0;
}

// This method overrides the BrassAccount print() method.
// As part of a BrassPlusAccount's print() functionality,
// it calls the BrassAccount print() method.
void BrassPlusAccount::print() {
    BrassAccount::print();
    cout << "Insufficient balance: $" << this->balance;
    cout << " Overdraft balance: $" << this->overdraftBalance << endl;
}

// Another example of overriding a base class's method
// and extending its functionality. We rely on the BrassAccount
// method to actually do the withdraw, but add our own functionality
// to deal with overdrafts.
bool BrassPlusAccount::withdraw(double amt) {
    if (BrassAccount::withdraw(amt)) {
        return true;
    } else {
        // Note - In class, we disregarded any existing balance in
        // calculating the overdraft. This code is different.
        // Here, we empty the account, and any remaining deficiency is
        // added to the overdraft balance.
        //
        // This is possible becaues this Account base class defines
        // balance as a protected variable (it was private in class).
        // We can access it directly from the BrassPlusAccount class,
        // since it descends from the Account abstract base class.
        double leftover = amt - this->balance;
        this->balance = 0.0;

        this->overdraftBalance += (1+this->overdraftPenalty) * (leftover);
        cout << "Overdraft balance now $" << this->overdraftBalance << endl;
        return true;
    }
}