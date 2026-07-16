#include <iostream>
using namespace std;

class Worker; // forward declaration

class Manager {
private:
    double salary;

public:
    Manager(double s) : salary(s) {}

    // friend function declaration
    friend void compareSalary(const Manager &m, const Worker &w);
};

class Worker {
private:
    double salary;

public:
    Worker(double s) : salary(s) {}

    // friend function declaration
    friend void compareSalary(const Manager &m, const Worker &w);
};

// friend function definition — has access to private members of both classes
void compareSalary(const Manager &m, const Worker &w) {
    if (m.salary > w.salary)
        cout << "Manager earns more (Manager: " << m.salary 
             << ", Worker: " << w.salary << ")" << endl;
    else if (m.salary < w.salary)
        cout << "Worker earns more (Manager: " << m.salary 
             << ", Worker: " << w.salary << ")" << endl;
    else
        cout << "Manager and Worker earn the same (" << m.salary << ")" << endl;
}

int main() {
    Manager m(75000);
    Worker w(50000);

    compareSalary(m, w);

    Manager m2(40000);
    Worker w2(40000);

    compareSalary(m2, w2);

    return 0;
}