#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    // Returns BY VALUE — returns a COPY of the (already modified) object
    Counter increment() {
        value++;
        return *this;   // a new temporary Counter is created and returned
    }

    // Returns BY REFERENCE — returns a reference to the ORIGINAL object
    Counter& incrementByRef() {
        value++;
        return *this;   // no copy made; refers to the same object
    }

    // Returns BY POINTER — returns the address of the ORIGINAL object
    Counter* incrementByPtr() {
        value++;
        return this;    // pointer to the same object
    }

    int getValue() const {
        return value;
    }
};

int main() {
    cout << "--- increment() chaining (returns by VALUE) ---" << endl;
    Counter c1(0);
    c1.increment().increment();  // compiles, but doesn't do what you'd expect!
    cout << "c1.getValue() = " << c1.getValue() << endl;  // prints 1, NOT 2

    cout << "\n--- incrementByRef() chaining (returns by REFERENCE) ---" << endl;
    Counter c2(0);
    c2.incrementByRef().incrementByRef();  // works as expected
    cout << "c2.getValue() = " << c2.getValue() << endl;  // prints 2

    cout << "\n--- incrementByPtr() chaining (returns by POINTER) ---" << endl;
    Counter c3(0);
    c3.incrementByPtr()->incrementByPtr();  // works, but needs -> syntax
    cout << "c3.getValue() = " << c3.getValue() << endl;  // prints 2

    return 0;
}