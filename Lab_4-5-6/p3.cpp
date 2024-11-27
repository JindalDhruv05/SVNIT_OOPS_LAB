#include<iostream>
#include<string>
using namespace std;

class Individual{
    string name;
    int income;
    double tax;
    public:
        void getData(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter income: ";
            cin>>income;
        }
        void compute(){
            if(income>200000)
                tax=0.3*(income-200000);
            else if(income>150000 && income<=200000)
                tax=0.2*(income-150000);
            else if(income>100000 && income<=150000)
                tax=0.1*(income-100000);
            else
                tax=0;
        }
        void printData(){
            cout<<"Name is "<<name;
            cout<<"\nTax is "<<tax;
        }
};

int main(){
    Individual i1;
    i1.getData();
    i1.compute();
    i1.printData();
}