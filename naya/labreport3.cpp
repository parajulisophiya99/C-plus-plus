#include <iostream>
using namespace std;

// Define enum class Color
enum class Color {
    RED,
    GREEN,
    BLUE
};

// Function to convert Color enum to string for display
string colorToString(Color c) {
    switch (c) {
        case Color::RED:   return "RED";
        case Color::GREEN: return "GREEN";
        case Color::BLUE:  return "BLUE";
        default:           return "UNKNOWN";
    }
}

// Shape class with a private Color member
class Shape {
private:
    Color color;

public:
    // Constructor to initialize color
    Shape(Color c) : color(c) {}

    // const member function to return the color
    Color getColor() const {
        return color;
    }
};

int main() {
    // Create a Shape object with color BLUE
    Shape shape(Color::BLUE);

    // Display its color
    cout << "The shape's color is: " << colorToString(shape.getColor()) << endl;

    return 0;
}