#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int serialNumber;

    static int counter; // static data member: shared by ALL Product objects

public:
    // Constructor: auto-generates a unique serial number using the counter
    Product(string productName) {
        name = productName;
        counter++;                  // increment shared counter for each new object
        serialNumber = counter;     // assign current counter value as this object's serial number
    }

    // Display individual product info
    void display() const {
        cout << "Product Name: " << name << " | Serial Number: " << serialNumber << endl;
    }

    // Static member function: belongs to the class, not any specific object
    // Can be called without an object, and can only access static members
    static int getTotalProducts() {
        return counter;
    }
};

// Definition (and initialization) of the static data member
// MUST be done outside the class, at file/global scope
int Product::counter = 0;

int main() {
    cout << "Total products before creating any: "
         << Product::getTotalProducts() << endl; // called using class name (no object needed)

    // Create multiple Product objects
    Product p1("Laptop");
    Product p2("Smartphone");
    Product p3("Tablet");
    Product p4("Headphones");

    cout << "\n--- Product Details ---\n";
    p1.display();
    p2.display();
    p3.display();
    p4.display();

    // Display total number of products created so far
    cout << "\nTotal products created: " << Product::getTotalProducts() << endl;
    // Could also call it via an object: p1.getTotalProducts(); (same result)

    return 0;
}