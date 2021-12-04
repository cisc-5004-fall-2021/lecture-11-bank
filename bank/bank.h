#include <string>

using namespace std;

// Abstract base Account class
// You cannot instantiate instances of Account, but you can use it as a base class
class Account {
    protected:
        // All Account objects have a balance, name, and account
        string name;
        int id;
        double balance;
    public:
        // Constructor for all classes derived from Account
        Account(string name, int id, double balance);
        // Pure virtual methods:
        virtual void deposit(double amt) = 0;
        virtual void print() = 0;
        virtual bool withdraw(double amt) = 0;
};

// BrassAccount is derived from Account
class BrassAccount: public Account {
    public:
        // BrassAccount constructor
        BrassAccount(string name, int id, double balance);

        // Implementations of pure virtual methods from the Account base class
        virtual void print();
        virtual void deposit(double amt);
        virtual bool withdraw(double amt);
};

// BrassPlusAccount is derived from BrassAccount
class BrassPlusAccount: public BrassAccount {
    private:
        // These private variables are unique to the BrassPlusAccount class
        double overdraftBalance;
        double overdraftPenalty;

    public:
        // BrassPlusAccount constructor
        BrassPlusAccount(string name, int id, double balance, double overdraftPenalty);

        // Override some methods implemented in the BrassAccount base class
        virtual bool withdraw(double amt);
        virtual void print();

        // This method is unique to the BrassPlusAccount class
        double getOverdraftBalance();
};