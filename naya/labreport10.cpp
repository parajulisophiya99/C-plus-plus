#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    // Constructor to initialize real and imag
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Member function that adds this object's value to another Complex
    // and returns a NEW Complex object (does not modify *this or c)
    Complex add(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Display the complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
        cout << endl;
    }
};

// Global function version (kept from before) — still works alongside the member function
Complex addComplex(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    // Create three Complex numbers
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(5, 6);

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c3 = "; c3.display();

    // Simple single addition using the member function
    Complex sum12 = c1.add(c2);
    cout << "\nc1.add(c2) = ";
    sum12.display();

    // Chaining: c1.add(c2).add(c3)
    // c1.add(c2) returns a temporary Complex object, and .add(c3) is
    // immediately called on THAT temporary object, returning another
    // temporary Complex which is finally assigned to chainedSum.
    Complex chainedSum = c1.add(c2).add(c3);
    cout << "c1.add(c2).add(c3) = ";
    chainedSum.display();

    // Chaining can continue further, and display() can even be
    // called directly at the end of the chain since it's const
    cout << "c1.add(c2).add(c3).add(c1) = ";
    c1.add(c2).add(c3).add(c1).display();

    return 0;
}