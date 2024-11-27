#include<iostream>
#include<string>
using namespace std;

class Patient{
public:
    Patient(){
        name = new string("");
        sex = new string("");
        age = 0;
        wardNumber = 0;
        bedNumber = 0;
        illness = new string("");
        dateOfAdmission = new string("");
        totalPatients++;
    }

    Patient(string n, string s, int a, int w, int b, string i, string d){
        name = new string(n);
        sex = new string(s);
        age = a;
        wardNumber = w;
        bedNumber = b;
        illness = new string(i);
        dateOfAdmission = new string(d);
        totalPatients++;
    }

    Patient(Patient &other){
        name = new string(*(other.name));
        sex = new string(*(other.sex));
        age = other.age;
        wardNumber = other.wardNumber;
        bedNumber = other.bedNumber;
        illness = new string(*(other.illness));
        dateOfAdmission = new string(*(other.dateOfAdmission));
        totalPatients++;
    }

    ~Patient(){
        delete name;
        delete sex;
        delete illness;
        delete dateOfAdmission;
        totalPatients--;
        cout << "Patient instance destroyed" << endl;
    }

    static void displayTotalPatients(){
        cout << "Total number of patients: " << totalPatients << endl;
    }

    void inputDetails(){
        cout << "Enter patient name: ";
        cin >> *name;
        cout << "Enter sex: ";
        cin >> *sex;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter ward number: ";
        cin >> wardNumber;
        cout << "Enter bed number: ";
        cin >> bedNumber;
        cout << "Enter nature of the illness: ";
        cin >> *illness;
        cout << "Enter date of admission: ";
        cin >> *dateOfAdmission;
    }

    void displayDetails(){
        cout << "Patient name: " << *name << endl;
        cout << "Sex: " << *sex << endl;
        cout << "Age: " << age << endl;
        cout << "Ward number: " << wardNumber << endl;
        cout << "Bed number: " << bedNumber << endl;
        cout << "Nature of the illness: " << *illness << endl;
        cout << "Date of admission: " << *dateOfAdmission << endl;
    }

    inline void setName(string& n){
        *name = n;
    }

    inline void setSex(string& s){
        *sex = s;
    }

    inline void setAge(int a){
        age = a;
    }

    inline void setWardNumber(int w){
        wardNumber = w;
    }

    inline void setBedNumber(int b){
        bedNumber = b;
    }

    inline void setIllness(string& i){
        *illness = i;
    }

    inline void setDateOfAdmission(string& d){
        *dateOfAdmission = d;
    }

    friend class Hospital;

private:
    string* name;
    string* sex;
    int age;
    int wardNumber;
    int bedNumber;
    string* illness;
    string* dateOfAdmission;
    static int totalPatients;
};

int Patient::totalPatients = 0;

class Hospital{
public:
    void showPatientDetails(Patient& patient){
        patient.displayDetails();
    }
};

int main(){
    Patient* patient1 = new Patient("Rahul", "Male", 30, 101, 5, "F1lu", "07-08-2024");
    patient1->displayDetails();

    Patient* patient2 = new Patient();
    patient2->inputDetails();
    patient2->displayDetails();

    Patient* patient3 = new Patient(*patient2);
    patient3->displayDetails();

    Hospital hospital;
    hospital.showPatientDetails(*patient1);

    Patient::displayTotalPatients();

    delete patient1;
    delete patient2;
    delete patient3;

    return 0;
}