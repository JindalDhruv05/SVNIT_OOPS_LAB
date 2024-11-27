#include<stdio.h>

typedef struct Complex{
    float real;
    float imag;
}Complex;

Complex add(Complex a, Complex b){
    Complex ans;
    ans.real=a.real+b.real;
    ans.imag=a.imag+b.imag;
    return ans;
}

Complex sub(Complex a, Complex b){
    Complex ans;
    ans.real=a.real-b.real;
    ans.imag=a.imag-b.imag;
    return ans;
}

Complex mul(Complex a, Complex b){
    Complex ans;
    ans.real=(a.real*b.real)-(a.imag*b.imag);
    ans.imag=(a.real*b.imag)+(a.imag*b.real);
    return ans;
}

Complex div(Complex a, Complex b){
    Complex den, temp, num;
    temp=b;
    temp.imag=-b.imag;
    den=mul(b,temp);
    num=mul(a,temp);
    num.real=num.real/den.real;
    num.imag=num.imag/den.real;
    return num;
}

void print(Complex obj){
    printf("%.0f+%.0fi",obj.real,obj.imag);
}

void menu(Complex a, Complex b, int op){
    Complex ans;
    switch(op){
        case 1:
            ans=add(a,b);
            print(ans);
            break;
        case 2:
            ans=sub(a,b);
            print(ans);
            break;
        case 3:
            ans=mul(a,b);
            print(ans);
            break;
        case 4:
            ans=div(a,b);
            print(ans);
            break;
        default:
            printf("Invalid operation");
            break;
    }
}

int main(){
    Complex a, b;
    printf("Enter complex numbers a and b in the form 'x+yi':\n");
    scanf("%f+%fi",&a.real,&a.imag);
    scanf("%f+%fi",&b.real,&b.imag);
    int op;
    printf("1:Addition\n2:Subtraction\n3:Multiplication\n4:Division\nEnter code: ");
    scanf("%d",&op);
    menu(a,b,op);
    return 0;
}   