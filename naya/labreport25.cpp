#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    static Logger *instance;   // static pointer to the single instance
    ofstream logFile;          // file stream used by every log() call

    // a. Private constructor: prevents direct instantiation from outside the class
    Logger() {
        logFile.open("log.txt", ios::app);   // append mode, so old logs aren't wiped
        if (!logFile.is_open()) {
            cerr << "Failed to open log.txt" << endl;
        } else {
            cout << "[Logger] File opened at construction. this = " 
                 << (void*)this << endl;
        }
    }

public:
    // Prevent copying/assignment, since a Singleton must never be duplicated
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Destructor: closes the file when the program ends
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
            cout << "[Logger] File closed at destruction." << endl;
        }
    }

    // c. Static function that returns the single shared instance
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();   // created only on the FIRST call
        }
        return instance;
    }

    // d. Writes a message to the log file
    void log(const string &message) {
        if (logFile.is_open()) {
            logFile << message << endl;
            cout << "Logged: \"" << message << "\" (via instance at " 
                 << (void*)this << ")" << endl;
        }
    }
};

// b. Definition/initialization of the static member (required outside the class)
Logger* Logger::instance = nullptr;

// --- Demonstrating access from different functions ---

void doTaskA() {
    Logger *logger = Logger::getInstance();
    logger->log("Task A started.");
    logger->log("Task A completed.");
}

void doTaskB() {
    Logger *logger = Logger::getInstance();
    logger->log("Task B is running.");
}

void doTaskC() {
    Logger *logger = Logger::getInstance();
    logger->log("Task C finished with no errors.");
}

int main() {
    cout << "--- Calling doTaskA() ---" << endl;
    doTaskA();

    cout << "\n--- Calling doTaskB() ---" << endl;
    doTaskB();

    cout << "\n--- Calling doTaskC() ---" << endl;
    doTaskC();

    cout << "\n--- Verifying same instance from main() directly ---" << endl;
    Logger *logger1 = Logger::getInstance();
    Logger *logger2 = Logger::getInstance();

    if (logger1 == logger2)
        cout << "Confirmed: logger1 and logger2 point to the SAME instance (" 
             << (void*)logger1 << ")" << endl;
    else
        cout << "ERROR: Different instances were created!" << endl;

    logger1->log("Final message from main().");

    return 0;
}