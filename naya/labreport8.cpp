#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    // Member function that uses the 'this' pointer to assign values
    void setData(int id, string name, double salary) {
        // Parameter names are same as data member names, so 'this->' is
        // required to distinguish the object's members from the parameters
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    // Getter functions
    int getId() const { return this->id; }
    string getName() const { return this->name; }
    double getSalary() const { return this->salary; }

    // Display employee details
    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Salary: " << salary << endl;
    }
};

// Function to find and display the employee with the highest salary
void findHighestSalary(Employee emp[], int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (emp[i].getSalary() > emp[highestIndex].getSalary()) {
            highestIndex = i;
        }
    }
    cout << "\nEmployee with the highest salary:\n";
    emp[highestIndex].display();
}

int main() {
    const int N = 5;
    Employee employees[N]; // array of Employee objects

    // Take input for 5 employees
    for (int i = 0; i < N; i++) {
        int id;
        string name;
        double salary;

        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Salary: ";
        cin >> salary;

        employees[i].setData(id, name, salary);
    }

    // Display all employee records
    cout << "\n--- All Employee Records ---\n";
    for (int i = 0; i < N; i++) {
        employees[i].display();
    }

    // Find and display the employee with the highest salary
    findHighestSalary(employees, N);

    return 0;
}