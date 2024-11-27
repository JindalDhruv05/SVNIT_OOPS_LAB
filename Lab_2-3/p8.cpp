#include<iostream>
#include<string>
using namespace std;

class PersonnelDatabase;

class InfoManager{
public:
    static void updateContactAddress(string &address, string &newAddress){
        address = newAddress;
    }

    static void updateTelephoneNumber(string &telephone, string &newTelephone){
        telephone = newTelephone;
    }
};

class PersonnelInfo{
private:
    string name;
    string dateOfBirth;
    string bloodGroup;
    double height;
    double weight;
    string insurancePolicyNumber;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

public:
    PersonnelInfo() : name("Unknown"), dateOfBirth("01-01-1900"), bloodGroup("Unknown"),
                      height(0.0), weight(0.0), insurancePolicyNumber("Unknown"), 
                      contactAddress("Unknown"), telephoneNumber("Unknown"), 
                      drivingLicenseNumber("Unknown") {}

    PersonnelInfo(string name, string dateOfBirth, string bloodGroup, double height, double weight, string insurancePolicyNumber, string contactAddress, string telephoneNumber, string drivingLicenseNumber) : name(name), dateOfBirth(dateOfBirth), bloodGroup(bloodGroup), height(height), weight(weight), insurancePolicyNumber(insurancePolicyNumber), contactAddress(contactAddress), telephoneNumber(telephoneNumber), drivingLicenseNumber(drivingLicenseNumber) {}

    PersonnelInfo(PersonnelInfo &info){
        name = info.name;
        dateOfBirth = info.dateOfBirth;
        bloodGroup = info.bloodGroup;
        height = info.height;
        weight = info.weight;
        insurancePolicyNumber = info.insurancePolicyNumber;
        contactAddress = info.contactAddress;
        telephoneNumber = info.telephoneNumber;
        drivingLicenseNumber = info.drivingLicenseNumber;
    }

    ~PersonnelInfo(){
        cout << "Destroying Personnel Info Object: " << name << endl;
    }

    void updateAddress(string &newAddress){
        InfoManager::updateContactAddress(contactAddress, newAddress);
    }

    void updateTelephone(string &newTelephone){
        InfoManager::updateTelephoneNumber(telephoneNumber, newTelephone);
    }

    static void displayOrganizationInfo(){
        cout << "Organization: ABC Corp Personnel Database" << endl;
    }

    void displayPersonnelInfo(){
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Insurance Policy Number: " << insurancePolicyNumber << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License Number: " << drivingLicenseNumber << endl;
    }

    friend class PersonnelDatabase;

    void* operator new(size_t size){
        cout << "Allocating memory for Personnel Info object\n";
        void* p = ::operator new(size);
        return p;
    }

    void operator delete(void* p){
        cout << "Deallocating memory for Personnel Info object\n";
        ::operator delete(p);
    }
};

class PersonnelDatabase{
public:
    void setPersonnelInfo(PersonnelInfo &info) {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, info.name);
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        getline(cin, info.dateOfBirth);
        cout << "Enter Blood Group: ";
        getline(cin, info.bloodGroup);
        cout << "Enter Height (in cm): ";
        cin >> info.height;
        cout << "Enter Weight (in kg): ";
        cin >> info.weight;
        cout << "Enter Insurance Policy Number: ";
        cin.ignore();
        getline(cin, info.insurancePolicyNumber);
        cout << "Enter Contact Address: ";
        getline(cin, info.contactAddress);
        cout << "Enter Telephone Number: ";
        getline(cin, info.telephoneNumber);
        cout << "Enter Driving License Number: ";
        getline(cin, info.drivingLicenseNumber);
    }
};

int main(){
    PersonnelInfo::displayOrganizationInfo();

    PersonnelInfo* person1 = new PersonnelInfo;

    PersonnelDatabase database;
    database.setPersonnelInfo(*person1);

    person1->displayPersonnelInfo();

    string newAddress;
    cout << "Enter new contact address: ";
    getline(cin, newAddress);
    person1->updateAddress(newAddress);

    string newTelephone;
    cout << "Enter new telephone number: ";
    getline(cin, newTelephone);
    person1->updateTelephone(newTelephone);

    cout << "Updated Personnel Information:" << endl;
    person1->displayPersonnelInfo();

    delete person1;

    return 0;
}