#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int size;

public:
    // Default constructor: creates an empty array
    Array() : data(nullptr), size(0) {
        cout << "[Default Constructor] Empty array created." << endl;
    }

    // Parameterized constructor: allocates array of given size, initializes to 0
    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
        cout << "[Parameterized Constructor] Array of size " << size 
             << " created at " << (void*)data << endl;
    }

    // Copy constructor: performs a DEEP copy
    Array(const Array &other) : size(other.size) {
        if (other.data == nullptr) {
            data = nullptr;
        } else {
            data = new int[size];             // allocate NEW, separate memory
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];      // copy each element's value
        }
        cout << "[Copy Constructor] Deep-copied array of size " << size 
             << " to new memory at " << (void*)data << endl;
    }

    // Destructor: frees allocated memory
    ~Array() {
        cout << "[Destructor] Freeing array at " << (void*)data << endl;
        delete[] data;
    }

    // Set a value at a given index
    void set(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
        else
            cout << "Index out of bounds!" << endl;
    }

    // Get a value at a given index
    int get(int index) const {
        if (index >= 0 && index < size)
            return data[index];
        cout << "Index out of bounds!" << endl;
        return -1;
    }

    // Display all elements
    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    cout << "--- Creating original array (size 5) ---" << endl;
    Array original(5);
    for (int i = 0; i < 5; i++)
        original.set(i, (i + 1) * 10);   // fill with 10, 20, 30, 40, 50

    cout << "Original: ";
    original.display();

    cout << "\n--- Copying original into a new array via copy constructor ---" << endl;
    Array copy = original;   // invokes the deep-copy constructor

    cout << "Copy:     ";
    copy.display();

    cout << "\n--- Modifying the ORIGINAL array ---" << endl;
    original.set(0, 999);
    original.set(2, 777);

    cout << "\n--- Comparing both arrays after modifying original ---" << endl;
    cout << "Original: ";
    original.display();
    cout << "Copy:     ";
    copy.display();

    cout << "\n(Notice the copy is unaffected by changes to the original — deep copy confirmed)" << endl;

    cout << "\n--- End of main, destructors will now run ---" << endl;
    return 0;
}