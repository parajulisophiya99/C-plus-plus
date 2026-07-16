#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    // Constructor to initialize real and imag
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Display the complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
        cout << endl;
    }
};

// Global function that takes two Complex objects by const reference
// and returns a new Complex object holding their sum
Complex addComplex(const Complex &c1, const Complex &c2) {
    int r = c1.real + c2.real;
    int i = c1.imag + c2.imag;
    return Complex(r, i);
}

int main() {
    // Create two Complex numbers
    Complex c1(3, 5);
    Complex c2(2, -4);

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    // Add them using the global function
    Complex result = addComplex(c1, c2);

    cout << "Sum: ";
    result.display();

    return 0;
}