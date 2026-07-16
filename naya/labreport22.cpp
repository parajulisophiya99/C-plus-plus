#include <iostream>
using namespace std;

class Point {
private:
    const int x;
    const int y;

public:
    // Constructor: const members MUST be initialized here, not in the body
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "[Constructor] Point created at (" << x << ", " << y << ")" << endl;
    }

    // Display the coordinates
    void display() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    cout << "--- Creating point1 ---" << endl;
    Point point1(3, 7);
    point1.display();

    cout << "\n--- Creating point2 ---" << endl;
    Point point2(-2, 5);
    point2.display();

    return 0;
}