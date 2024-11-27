#include<iostream>
using namespace std;

class C1{
    float n;
    public:
    C1(float x){
        n=x;
    }
    friend class Sum;
};

class C2{
    float n;
    public:
    C2(float x){
        n=x;
    }
    friend class Sum;  
};

class Sum{
    public:
    static void sum(C1 a, C2 b){
        cout<<(a.n+b.n)/2<<endl;
    }
};

int main(){
    float n1, n2;
    cout<<"Enter number 1: ";
    cin>>n1;
    cout<<"Enter number 2: ";
    cin>>n2;
    C1 a(n1);
    C2 b(n2);
    Sum::sum(a,b);
}