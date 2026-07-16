#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

    // Private member function to convert Celsius to Fahrenheit
    double toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

public:
    // Constructor to initialize celsius
    Temperature(double c) : celsius(c) {}

    // Public function that displays both Celsius and Fahrenheit
    void display() const {
        double fahrenheit = toFahrenheit(); // calling the private function internally
        cout << "Temperature: " << celsius << "°C = " << fahrenheit << "°F" << endl;
    }
};

int main() {
    // Create Temperature objects
    Temperature temp1(0.0);
    Temperature temp2(37.0);
    Temperature temp3(100.0);

    // Display temperatures (Celsius and Fahrenheit)
    temp1.display();
    temp2.display();
    temp3.display();

    return 0;
}