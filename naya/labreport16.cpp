#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function declaration: overloads operator+
    friend Complex operator+(const Complex &c1, const Complex &c2);

    // Display the complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

// Friend function definition: has access to private members of both objects
Complex operator+(const Complex &c1, const Complex &c2) {
    // Directly access private members since this function is a friend
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, -2.5);

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    // This works because of the overloaded operator+
    Complex c3 = c1 + c2;

    cout << "\nc1 + c2 = ";
    c3.display();

    return 0;
}