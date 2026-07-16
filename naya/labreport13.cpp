#include <iostream>
using namespace std;

class DataStorage {
private:
    int secret;

public:
    DataStorage(int s) : secret(s) {}

    // Grant DataProcessor full access to private members
    friend class DataProcessor;

    // Regular public method for normal (non-friend) access
    void display() const {
        cout << "Current secret value: " << secret << endl;
    }
};

class DataProcessor {
public:
    // Read the private secret directly (allowed because of friendship)
    void readSecret(const DataStorage &ds) {
        cout << "DataProcessor read secret: " << ds.secret << endl;
    }

    // Modify the private secret directly (allowed because of friendship)
    void modifySecret(DataStorage &ds, int newValue) {
        cout << "DataProcessor changing secret from " << ds.secret 
             << " to " << newValue << endl;
        ds.secret = newValue;
    }

    // Perform some operation on the secret, e.g. doubling it
    void doubleSecret(DataStorage &ds) {
        ds.secret *= 2;
        cout << "DataProcessor doubled the secret. New value: " << ds.secret << endl;
    }
};

int main() {
    DataStorage storage(42);
    DataProcessor processor;

    storage.display();          // Normal public access
    processor.readSecret(storage);   // Friend class reading private data
    processor.modifySecret(storage, 100); // Friend class modifying private data
    storage.display();

    processor.doubleSecret(storage); // Friend class manipulating private data
    storage.display();

    return 0;
}