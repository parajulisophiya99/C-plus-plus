#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>
using namespace std;

class FileHandler {
private:
    FILE *filePtr;
    string filename;

public:
    // Constructor: opens the file in write mode
    FileHandler(const string &fname) : filename(fname) {
        filePtr = fopen(fname.c_str(), "w");
        if (filePtr == nullptr) {
            cerr << "[Constructor] Failed to open \"" << fname 
                 << "\": " << strerror(errno) << endl;
        } else {
            cout << "[Constructor] Opened \"" << fname 
                 << "\" in write mode." << endl;
        }
    }

    // Destructor: closes the file if it's open
    ~FileHandler() {
        if (filePtr != nullptr) {
            fclose(filePtr);
            cout << "[Destructor] Closed \"" << filename << "\"." << endl;
        }
    }

    // Write a single line to the file (appends a newline)
    void writeLine(const string &line) {
        if (filePtr == nullptr) {
            cerr << "Cannot write: file is not open." << endl;
            return;
        }
        fprintf(filePtr, "%s\n", line.c_str());
    }

    // Check if the file was opened successfully
    bool isOpen() const {
        return filePtr != nullptr;
    }
};

int main() {
    cout << "--- Creating FileHandler and writing lines ---" << endl;
    {
        FileHandler fh("output.txt");   // constructor opens the file

        if (fh.isOpen()) {
            fh.writeLine("Hello, this is line 1.");
            fh.writeLine("Here is line 2.");
            fh.writeLine("And finally, line 3.");
            cout << "Lines written to output.txt" << endl;
        }

        cout << "--- End of inner scope, fh is about to be destroyed ---" << endl;
    }   // <-- fh goes out of scope here; destructor runs automatically, closing the file

    cout << "\n--- Back in main(), file has already been closed ---" << endl;
    cout << "You can now safely reopen or read output.txt elsewhere in the program." << endl;

    return 0;
}