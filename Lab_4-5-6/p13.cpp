#include<iostream>
using namespace std;

class Integer{
private:
    int value;

public:
    Integer():value(0){}

    Integer(int v):value(v){}

    friend Integer operator+(Integer& obj1, Integer& obj2){
        return Integer(obj1.value + obj2.value);
    }

    void display(){
        cout<<value<<endl;
    }
};

int main(){
    Integer num1(10),num2(20);

    Integer sum=num1+num2;

    cout<<"The sum is: ";
    sum.display();

    return 0;
}