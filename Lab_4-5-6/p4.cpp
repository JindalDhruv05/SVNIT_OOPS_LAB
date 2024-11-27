#include<iostream>
#include<string>
using namespace std;

class Account{
    string name, type;
    int ac_no;
    float bal=0;
    public:
        void getData(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter account number: ";
            cin>>ac_no;
            cout<<"Enter account type: ";
            cin>>type;
        }
        void deposit(){
            float x;
            cout<<"Enter amount to deposit: ";
            cin>>x;
            bal+=x;
            cout<<"Transaction Successful"<<endl;
        }
        void withdraw(){
            float x;
            cout<<"Enter amount to withdraw: ";
            cin>>x;
            if(bal<x)
                cout<<"Insufficient Funds."<<endl;
            else{
                bal-=x;
                cout<<"Transaction Successful"<<endl;
            }
        }
        void printData(){
            cout<<"Name: "<<name<<endl;
            cout<<"Account Number: "<<ac_no<<endl;
            cout<<"Account Type: "<<type<<endl;
            cout<<"Current Balance: "<<bal<<endl;
        }
};

int main(){
    Account p1;
    p1.getData();
    p1.deposit();
    p1.withdraw();
    p1.printData();
}