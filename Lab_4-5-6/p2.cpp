#include<iostream>
#include<string>
using namespace std;

class Customer{
    string name;
    int calls;
    float bill;
    public:
        void getData(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter number of calls: ";
            cin>>calls;
        }
        void compute(){
            if(calls>200)
                bill=200+0.6*50+0.5*50+0.4*(calls-200);
            else if(calls>150 && calls<=200)
                bill=200+0.6*50+0.5*(calls-150);
            else if(calls>100 && calls<=150)
                bill=200+0.6*(calls-100);
            else
                bill=200;
        }
        void printData(){
            cout<<"Name is "<<name;
            cout<<"\nBill is "<<bill;
        }
};

int main(){
    Customer c1;
    c1.getData();
    c1.compute();
    c1.printData();
}