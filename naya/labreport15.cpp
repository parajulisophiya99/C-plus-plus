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
        cout << "[Constructor] \"" << data << "\" at " << (void*)data << endl;
    }

    // Copy constructor: performs a DEEP copy
    MyString(const MyString &other) {
        data = new char[strlen(other.data) + 1];  // allocate NEW memory
        strcpy(data, other.data);                 // copy the actual characters
        cout << "[Copy Constructor] \"" << data << "\" at " << (void*)data 
             << " (deep-copied from " << (void*)other.data << ")" << endl;
    }

    // Copy assignment operator: also needed for deep copy safety (Rule of Three)
    MyString& operator=(const MyString &other) {
        cout << "[Copy Assignment] assigning \"" << other.data << "\"" << endl;
        if (this == &other) return *this;   // guard against self-assignment

        delete[] data;                       // free old memory
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        return *this;
    }

    // Destructor: frees the allocated memory
    ~MyString() {
        cout << "[Destructor] freeing " << (void*)data 
             << " (\"" << data << "\")" << endl;
        delete[] data;
    }

    // Display the string
    void display() const {
        cout << "String: " << data << endl;
    }

    // Append another MyString to this one (deep copy + reallocation)
    void append(const MyString &other) {
        int newLength = strlen(data) + strlen(other.data) + 1; // +1 for '\0'
        char *newData = new char[newLength];

        strcpy(newData, data);       // copy existing content
        strcat(newData, other.data); // concatenate the other string

        delete[] data;                // free the old buffer
        data = newData;               // point to the new, larger buffer

        cout << "[Append] Result: \"" << data << "\"" << endl;
    }
};

// Function that takes a MyString BY VALUE — now safe thanks to deep copy
void printString(MyString s) {
    cout << "Inside printString: ";
    s.display();
    // 's' is destroyed here, but it owns its OWN memory now — no double free
}

int main() {
    cout << "--- Creating str1 ---" << endl;
    MyString str1("Hello");

    cout << "\n--- Passing str1 by value to printString() ---" << endl;
    printString(str1);   // triggers copy constructor, safely

    cout << "\n--- str1 still valid after the call ---" << endl;
    str1.display();

    cout << "\n--- Demonstrating deep copy explicitly ---" << endl;
    MyString str2 = str1;   // copy constructor invoked
    str2.append(MyString(" World"));  // modify str2 only
    cout << "str1 is unaffected: ";
    str1.display();
    cout << "str2 has changed:  ";
    str2.display();

    cout << "\n--- Demonstrating append() ---" << endl;
    MyString greeting("Hello");
    MyString name(", Claude!");
    greeting.append(name);
    greeting.display();

    cout << "\n--- Demonstrating copy assignment ---" << endl;
    MyString str3("Temporary");
    str3 = greeting;   // copy assignment invoked
    str3.display();

    cout << "\n--- End of main, destructors will now run ---" << endl;
    return 0;
}