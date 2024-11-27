#include<iostream>
#include<string>
using namespace std;

class Publication{
    string title, author;
    float price;
    protected:
        void getData(){
            cout<<"Enter the title: ";
            cin>>title;
            cout<<"Enter author's name: ";
            cin>>author;
            cout<<"Enter the price: ";
            cin>>price;
        }
        void displayData(){
            cout<<"Title: "<<title<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Price: "<<price<<endl;
        }
};

class Book:Publication{
    int pcount;
    public:
        void getData(){
            Publication::getData();
            cout<<"Enter number of pages: ";
            cin>>pcount;
        }
        void displayData(){
            Publication::displayData();
            cout<<"The number of pages are: "<<pcount<<endl;
        }
};

class Ebook:Publication{
    int ptime;
    public:
        void getData(){
            Publication::getData();
            cout<<"Enter runtime: ";
            cin>>ptime;
        }
        void displayData(){
            Publication::displayData();
            cout<<"Runtime: "<<ptime<<endl;
        }
};

int main(){
    Book b1;
    Ebook e1;
    b1.getData();
    e1.getData();
    b1.displayData();
    e1.displayData();
}