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

void menu(Arithmetic obj, int op){
    switch(op){
        case 1:
            add(obj);
            break;
        case 2:
            sub(obj);
            break;
        case 3:
            mul(obj);
            break;
        case 4:
            div(obj);
            break;
        default:
            printf("Invalid operation");
            break;
    }
}

int main(){
    Arithmetic obj;
    int op;
    printf("Enter number 1: ");
    scanf("%d",&obj.no1);\
    printf("Enter number 2: ");
    scanf("%d",&obj.no2);
    printf("1:Addition\n2:Subtraction\n3:Multiplication\n4:Division\nEnter code: ");
    scanf("%d",&op);
    menu(obj,op);
    return 0;
}