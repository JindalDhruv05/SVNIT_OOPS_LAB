#include<iostream>
#include<string>
using namespace std;

class Employee{
    string name;
    int earning, bonus;
    public:
        void getData(){
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Earning: ";
            cin>>earning;
        }
        void compute(){
            if(earning>2000)
                bonus=0.1*earning;
            else
                bonus=0;
        }
        void printData(){
            cout<<"Name is "<<name;
            cout<<"\nBonus is "<<bonus;
        }
};

int main(){

    Employee e1;
    e1.getData();
    e1.compute();
    e1.printData();
}