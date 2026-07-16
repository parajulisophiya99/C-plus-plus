#include <iostream>
using namespace std;

class Complex {
private:
    int *real;
    int *imag;

public:
    // Default constructor: allocates memory, sets real and imag to 0
    Complex() {
        real = new int(0);
        imag = new int(0);
        cout << "[Default Constructor] Complex(0, 0) created. real at " 
             << (void*)real << ", imag at " << (void*)imag << endl;
    }

    // Parameterized constructor: allocates memory, sets given values
    Complex(int r, int i) {
        real = new int(r);
        imag = new int(i);
        cout << "[Parameterized Constructor] Complex(" << *real << ", " 
             << *imag << ") created. real at " << (void*)real 
             << ", imag at " << (void*)imag << endl;
    }

    // Copy constructor: performs a DEEP copy (new memory, same values)
    Complex(const Complex &other) {
        real = new int(*other.real);   // allocate new int, copy the VALUE
        imag = new int(*other.imag);
        cout << "[Copy Constructor] Deep-copied Complex(" << *real << ", " 
             << *imag << "). New real at " << (void*)real 
             << ", new imag at " << (void*)imag << endl;
    }

    // Destructor: frees the dynamically allocated memory
    ~Complex() {
        cout << "[Destructor] Freeing Complex(" << *real << ", " << *imag 
             << ") -> real at " << (void*)real << ", imag at " << (void*)imag << endl;
        delete real;
        delete imag;
    }

    // Modify the real part (used to prove deep copy independence)
    void setReal(int r) {
        *real = r;
    }

    // Display the complex number in a+bi form
    void display() const {
        if (*imag >= 0)
            cout << *real << " + " << *imag << "i" << endl;
        else
            cout << *real << " - " << -(*imag) << "i" << endl;
    }
};

int main() {
    cout << "--- Default constructor ---" << endl;
    Complex c1;
    c1.display();

    cout << "\n--- Parameterized constructor ---" << endl;
    Complex c2(3, 4);
    c2.display();

    cout << "\n--- Copy constructor ---" << endl;
    Complex c3 = c2;   // invokes copy constructor
    c3.display();

    cout << "\n--- Proving the copy is independent (deep copy) ---" << endl;
    c3.setReal(99);
    cout << "c2 (original): ";
    c2.display();
    cout << "c3 (modified copy): ";
    c3.display();

    cout << "\n--- Another parameterized example ---" << endl;
    Complex c4(-2, -7);
    c4.display();

    cout << "\n--- End of main(), destructors will now run in reverse order ---" << endl;
    return 0;
}