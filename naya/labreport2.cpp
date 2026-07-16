#include <iostream>
#include <string>
using namespace std;

// Define the Student struct
struct Student {
    string name;
    int rollNumber;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore(); // ignore leftover newline before using getline

    // Dynamically allocate an array of Student objects
    Student *students = new Student[n];

    // Input data for each student
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cin.ignore(); // ignore newline after reading roll number
    }

    // Display all student data
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": Name = " << students[i].name
             << ", Roll Number = " << students[i].rollNumber << endl;
    }

    // Deallocate memory
    delete[] students;

    return 0;
}