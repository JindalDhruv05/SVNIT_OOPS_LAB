#include<iostream>
#include<string>
using namespace std;

class Payroll;

class TaxCalculator{
public:
    static double calculateTax(double grossPay){
        return grossPay * 0.1;
    }
};

class Employee{
private:
    string name;
    int code;
    string designation;
    long accountNumber;
    string dateOfJoining;
    double basicPay;
    double DA;
    double HRA;
    double CCA;
    double deductions;
    double grossPay;
    double netPay;

public:
    Employee(): 
        name("Unknown"), code(0), designation("None"), accountNumber(0), dateOfJoining("01-01-2000"), basicPay(0.0), DA(0.0), HRA(0.0), CCA(0.0), deductions(0.0), grossPay(0.0), netPay(0.0){}

    Employee(string name, int code, string designation, long accountNumber, string dateOfJoining, double basicPay, double DA, double HRA, double CCA, double deductions): 
        name(name), code(code), designation(designation), accountNumber(accountNumber), dateOfJoining(dateOfJoining), basicPay(basicPay), DA(DA), HRA(HRA), CCA(CCA), deductions(deductions){
        calculatePay();
    }

    Employee(Employee &emp){
        name = emp.name;
        code = emp.code;
        designation = emp.designation;
        accountNumber = emp.accountNumber;
        dateOfJoining = emp.dateOfJoining;
        basicPay = emp.basicPay;
        DA = emp.DA;
        HRA = emp.HRA;
        CCA = emp.CCA;
        deductions = emp.deductions;
        grossPay = emp.grossPay;
        netPay = emp.netPay;
    }

    ~Employee(){
        cout<<"Destroying Employee Object: "<<name<<endl;
    }

    void calculatePay(){
        grossPay = basicPay + DA + HRA + CCA;
        netPay = grossPay - deductions - TaxCalculator::calculateTax(grossPay);
    }

    static void displayOrganization(){
        cout<<"Organization: DJ Industries"<<endl;
    }

    void displayEmployee(){
        cout << "Name: " << name << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
        cout << "Basic Pay: " << basicPay << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "CCA: " << CCA << endl;
        cout << "Gross Pay: " << grossPay << endl;
        cout << "Deductions: " << deductions << endl;
        cout << "Net Pay: " << netPay << endl;
    }

    friend class Payroll;

    void* operator new(size_t size) {
        cout << "Allocating memory for Employee object\n";
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p) {
        cout << "Deallocating memory for Employee object\n";
        ::operator delete(p);
    }
};

class Payroll{
public:
    void setEmployeeDetails(Employee &emp){
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Enter Employee Code: ";
        cin >> emp.code;
        cout << "Enter Designation: ";
        cin.ignore();
        getline(cin, emp.designation);
        cout << "Enter Account Number: ";
        cin >> emp.accountNumber;
        cout << "Enter Date of Joining: ";
        cin.ignore();
        getline(cin, emp.dateOfJoining);
        cout << "Enter Basic Pay: ";
        cin >> emp.basicPay;
        cout << "Enter DA: ";
        cin >> emp.DA;
        cout << "Enter HRA: ";
        cin >> emp.HRA;
        cout << "Enter CCA: ";
        cin >> emp.CCA;
        cout << "Enter Deductions: ";
        cin >> emp.deductions;
        
        emp.calculatePay();
    }
};

int main(){
    Employee::displayOrganization();

    Employee* emp1 = new Employee;

    Payroll payroll;
    payroll.setEmployeeDetails(*emp1);

    emp1->displayEmployee();

    delete emp1;

    return 0;
}