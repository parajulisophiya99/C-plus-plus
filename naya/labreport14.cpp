#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char *data;

public:
    // Constructor: allocates memory and copies the string in
    MyString(const char *str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        cout << "Constructor called for \"" << data << "\" at address " 
             << (void*)data << endl;
    }

    // Destructor: frees the allocated memory
    ~MyString() {
        cout << "Destructor called for address " << (void*)data << endl;
        delete[] data;
    }

    // Display the string
    void display() const {
        cout << "String: " << data << endl;
    }
};

// Function that takes a MyString BY VALUE
void printString(MyString s) {
    s.display();
    // 's' is a local copy — it gets destroyed when this function returns
}

int main() {
    MyString str1("Hello, World!");
    str1.display();

    cout << "\nCalling printString(str1)...\n" << endl;
    printString(str1);   // Passed by value -> triggers a shallow copy

    cout << "\nBack in main, using str1 again:\n" << endl;
    str1.display();      // Undefined behavior may occur here too

    return 0;
}