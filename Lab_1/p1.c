#include<stdio.h>

typedef struct Arithmetic{
    int no1;
    int no2;
}Arithmetic;

void add(Arithmetic obj){
    printf("Addition is %d\n",obj.no1+obj.no2);
}

void sub(Arithmetic obj){
    printf("Subtraction is %d\n",obj.no1-obj.no2);
}

void mul(Arithmetic obj){
    printf("Multiplication is %d\n",obj.no1*obj.no2);
}

void div(Arithmetic obj){
    printf("Division is %.2f\n",(float)obj.no1/obj.no2);
}

int main(){
    Arithmetic obj;
    scanf("%d",&obj.no1);
    scanf("%d",&obj.no2);
    add(obj);
    sub(obj);
    mul(obj);
    div(obj);
    return 0;
}