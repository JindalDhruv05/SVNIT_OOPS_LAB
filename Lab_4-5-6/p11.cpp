#include<iostream>
using namespace std;

class Integer{
private:
    int value;

public:
    Integer():value(0){}

    Integer(int v):value(v){}

    friend ostream& operator<<(ostream& os, const Integer& obj){
        os<<obj.value;
        return os;
    }

    friend istream& operator>>(istream& is, Integer& obj){
        is>>obj.value;
        return is;
    }
};

int main(){
    Integer num;

    cout<<"Enter an integer: ";
    cin>>num;

    cout<<"You entered: "<<num<<endl;

    return 0;
}
