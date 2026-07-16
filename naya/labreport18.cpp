#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Default constructor: sets radius to 0
    Circle() : radius(0) {
        cout << "[Default Constructor] radius set to " << radius << endl;
    }

    // Parameterized constructor: sets radius to a given value
    Circle(double r) : radius(r) {
        cout << "[Parameterized Constructor] radius set to " << radius << endl;
    }

    // Calculates and returns the area of the circle
    double area() const {
        const double PI = 3.14159265358979;
        return PI * radius * radius;
    }

    // Helper to display info
    void display() const {
        cout << "Radius: " << radius << ", Area: " << area() << endl;
    }
};

int main() {
    cout << "--- Creating circle1 using default constructor ---" << endl;
    Circle circle1;              // calls default constructor
    circle1.display();

    cout << "\n--- Creating circle2 using parameterized constructor ---" << endl;
    Circle circle2(5.0);         // calls parameterized constructor
    circle2.display();

    cout << "\n--- Creating circle3 using parameterized constructor ---" << endl;
    Circle circle3(2.5);
    circle3.display();

    return 0;
}