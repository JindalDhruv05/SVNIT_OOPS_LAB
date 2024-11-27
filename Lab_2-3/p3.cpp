#include<iostream>
#include<string>
using namespace std;

class Employee{
public:
    Employee(){
        name = new string("");
        code=0;
        designation = new string("");
        exp=0;
        age=0;
    }

    Employee(string n, int c, string d, int y, int a) {
        name = new string(n);
        code = c;
        designation = new string(d);
        exp = y;
        age = a;
    }

    Employee(Employee &other){
        name = new string(*(other.name));
        code = other.code;
        designation = new string(*(other.designation));
        exp = other.exp;
        age = other.age;
    }

    ~Employee(){
        delete name;
        delete designation;
        cout<<"Employee instance destroyed"<< endl;
    }

    static void displayTotalEmployees(){
        cout<<"Total number of employees: "<<totalEmployees<<endl;
    }

    void inputDetails(){
        cout << "Enter employee name: ";
        cin >> *name;
        cout << "Enter employee code: ";
        cin >> code;
        cout << "Enter designation: ";
        cin >> *designation;
        cout << "Enter years of experience: ";
        cin >> exp;
        cout << "Enter age: ";
        cin >> age;
        totalEmployees++;
    }

    void displayDetails(){
        cout << "Employee name: " << *name << endl;
        cout << "Employee code: " << code << endl;
        cout << "Designation: " << *designation << endl;
        cout << "Years of experience: " << exp << endl;
        cout << "Age: " << age << endl;
    }

    inline void setName(string& n) {
        *name = n;
    }

    inline void setCode(int c) {
        code = c;
    }

    inline void setDesignation(const string& d) {
        *designation = d;
    }

    inline void setYearsOfExperience(int y) {
        exp = y;
    }

    inline void setAge(int a) {
        age = a;
    }

    friend class HR;

private:
    string* name;
    int code;
    string* designation;
    int exp;
    int age;
    static int totalEmployees;
};

int Employee::totalEmployees = 0;

class HR{
public:
    void showEmployeeDetails(Employee& emp){
        emp.displayDetails();
    }
};

int main(){
    Employee* emp1 = new Employee("Rahul", 101, "Manager", 10, 45);
    emp1->displayDetails();

    Employee* emp2 = new Employee();
    emp2->inputDetails();
    emp2->displayDetails();

    Employee* emp3 = new Employee(*emp2);
    emp3->displayDetails();

    HR hr;
    hr.showEmployeeDetails(*emp1);

    Employee::displayTotalEmployees();

    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}