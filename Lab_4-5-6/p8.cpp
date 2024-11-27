#include<iostream>
using namespace std;

class Complex{
private:
    float real;
    float imag;
public:
    Complex(float r=0, float i=0):real(r),imag(i){}

    inline Complex multiply(Complex &c);

    void display();

    void Complex::display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

inline Complex Complex::multiply(Complex &c){
    Complex result;
    result.real=this->real*c.real-this->imag*c.imag;
    result.imag=this->real*c.imag+this->imag*c.real;
    return result;
}

int main(){
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex result = c1.multiply(c2);

    cout << "The product of the complex numbers is: ";
    result.display();

    return 0;
}