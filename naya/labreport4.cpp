#include <iostream>
using namespace std;

class MathOperations {
public:
    // a. Two integers
    int multiply(int a, int b) {
        return a * b;
    }

    // b. Three integers, with default argument for the third (c = 1)
    int multiply(int a, int b, int c = 1) {
        return a * b * c;
    }

    // c. A double and an integer (integer is a multiplier)
    double multiply(double a, int b) {
        return a * b;
    }
};

int main() {
    MathOperations math;
    
    // a. Two integers
    cout << "multiply(4, 5) = " << math.multiply(3, 4, 5) << endl;

    // b. Three integers (explicit)
    cout << "multiply(2, 3, 4) = " << math.multiply(2, 3, 4) << endl;

    // b. Three integers (using default argument, c = 1)
    cout << "multiply(6, 7) using default c=1 -> ";
    // Note: This call is ambiguous with the two-int version, see explanation below
    cout << math.multiply(6, 7, 1) << endl;

    // c. Double and integer
    cout << "multiply(2.5, 4) = " << math.multiply(2.5, 4) << endl;

    return 0;
}