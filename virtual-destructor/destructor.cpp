#include <iostream>
using namespace std;

class BaseClass {
    public:
        BaseClass() {
            cout << "BaseClass constructor" << endl;
            num = 1000;
        }
        virtual ~BaseClass() {
            cout << "BaseClass destructor" << endl;
        }
    private:
        int num;
};

// These classes demonstrate the importance of a virtual destructor.
// Try making the destructor non-virtual: it wll cause a memory leak
// in the main() function below by not deallocating the dynamically
// allocated array.

class DerivedClass: public BaseClass {
    public:
        DerivedClass() {
            cout << "DerivedClass constructor, allocating 300 ints" << endl;
            arr = new int[300];
        }
        virtual ~DerivedClass() {
            cout << "DerivedClass destructor, deallocating 300 ints" << endl;
            delete [] arr;
        }

    private:
        int *arr;
};

int main() {
    BaseClass *d = new DerivedClass();
    delete d;
}