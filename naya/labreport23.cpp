#include <iostream>
using namespace std;

class Base {
public:
    // Base constructor
    Base() {
        cout << "Base constructor called" << endl;
    }

    // Base destructor
    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    // Derived constructor
    Derived() {
        cout << "Derived constructor called" << endl;
    }

    // Derived destructor
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    cout << "--- Creating a Derived object ---" << endl;
    Derived d;

    cout << "\n--- End of main(), d is about to be destroyed ---" << endl;
    return 0;
}   // d goes out of scope here, triggering destructor calls