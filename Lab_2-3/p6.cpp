#include<iostream>
#include<string>
using namespace std;

class MarkSheet;

class ResultCalculator{
public:
    static double calculateTotal(double internalMarks, double externalMarks){
        return internalMarks + externalMarks;
    }
    
    static char calculateGrade(double totalMarks){
        if (totalMarks >= 90) 
            return 'A';
        else if (totalMarks >= 75) 
            return 'B';
        else if (totalMarks >= 60) 
            return 'C';
        else if (totalMarks >= 50) 
            return 'D';
        else return 'F';
    }
};

class Student{
private:
    string name;
    int rollNumber;
    string subjectCode;
    string subjectName;
    double internalMarks;
    double externalMarks;
    double totalMarks;
    char grade;

public:
    Student(): 
        name("Unknown"), rollNumber(0), subjectCode(""), subjectName(""), internalMarks(0.0), externalMarks(0.0), totalMarks(0.0), grade('F'){}

    Student(string name, int rollNumber, string subjectCode, string subjectName, double internalMarks, double externalMarks): 
        name(name), rollNumber(rollNumber), subjectCode(subjectCode), subjectName(subjectName), internalMarks(internalMarks), externalMarks(externalMarks){
        calculateResult();
    }

    Student(Student &student){
        name = student.name;
        rollNumber = student.rollNumber;
        subjectCode = student.subjectCode;
        subjectName = student.subjectName;
        internalMarks = student.internalMarks;
        externalMarks = student.externalMarks;
        totalMarks = student.totalMarks;
        grade = student.grade;
    }

    ~Student(){
        cout << "Destroying Student Object: " << name << endl;
    }

    void calculateResult(){
        totalMarks = ResultCalculator::calculateTotal(internalMarks, externalMarks);
        grade = ResultCalculator::calculateGrade(totalMarks);
    }

    static void displayUniversity(){
        cout << "University: Great University" << endl;
    }

    void displayMarkSheet(){
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject Code: " << subjectCode << endl;
        cout << "Subject Name: " << subjectName << endl;
        cout << "Internal Marks: " << internalMarks << endl;
        cout << "External Marks: " << externalMarks << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Grade: " << grade << endl;
    }

    friend class MarkSheet;

    void* operator new(size_t size){
        cout << "Allocating memory for Student object\n";
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p){
        cout << "Deallocating memory for Student object\n";
        ::operator delete(p);
    }
};

class MarkSheet{
public:
    void setStudentDetails(Student &student){
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, student.name);
        cout << "Enter Roll Number: ";
        cin >> student.rollNumber;
        cout << "Enter Subject Code: ";
        cin.ignore();
        getline(cin, student.subjectCode);
        cout << "Enter Subject Name: ";
        getline(cin, student.subjectName);
        cout << "Enter Internal Marks: ";
        cin >> student.internalMarks;
        cout << "Enter External Marks: ";
        cin >> student.externalMarks;
        
        student.calculateResult();
    }
};

int main(){
    Student::displayUniversity();

    Student* student1 = new Student;

    MarkSheet markSheet;
    markSheet.setStudentDetails(*student1);

    student1->displayMarkSheet();

    delete student1;

    return 0;
}
