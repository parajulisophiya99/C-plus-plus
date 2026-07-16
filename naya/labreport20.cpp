#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // a. Default constructor: sets time to 00:00:00
    Time() : hours(0), minutes(0), seconds(0) {
        cout << "[Default Constructor] Time set to 00:00:00" << endl;
    }

    // b. Parameterized constructor: takes hours, minutes, seconds directly
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        cout << "[Parameterized Constructor] Time set to " << h << ":" 
             << m << ":" << s << endl;
        normalize();  // handle out-of-range values, e.g. Time(1, 90, 0)
    }

    // c. Single integer constructor: takes total seconds, converts to H:M:S
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        cout << "[Single-Int Constructor] " << totalSeconds 
             << " seconds converted to time" << endl;
    }

    // Display the time in HH:MM:SS format
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }

private:
    // Helper to fix overflow if minutes/seconds exceed 59 (used by constructor b)
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }
};

int main() {
    cout << "--- Default constructor ---" << endl;
    Time t1;                  // 00:00:00
    t1.display();

    cout << "\n--- Parameterized constructor (9, 45, 30) ---" << endl;
    Time t2(9, 45, 30);       // 09:45:30
    t2.display();

    cout << "\n--- Parameterized constructor with overflow (1, 90, 75) ---" << endl;
    Time t3(1, 90, 75);       // normalizes to 02:31:15
    t3.display();

    cout << "\n--- Single integer constructor (3661 seconds) ---" << endl;
    Time t4(3661);            // 1 hour, 1 minute, 1 second -> 01:01:01
    t4.display();

    cout << "\n--- Single integer constructor (7325 seconds) ---" << endl;
    Time t5(7325);            // 02:02:05
    t5.display();

    return 0;
}