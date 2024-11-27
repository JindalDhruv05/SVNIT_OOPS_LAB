#include<iostream>
#include<vector>
using namespace std;

class Vector{
private:
    vector<int> elements;

public:
    Vector(){}

    Vector(vector<int>& elems):elements(elems){}

    friend ostream& operator<<(ostream& os, Vector& v){
        os<<"[";
        for(size_t i=0;i<v.elements.size();i++){
            os<<v.elements[i];
            if(i<v.elements.size()-1)os<<", ";
        }
        os<<"]";
        return os;
    }

    friend istream& operator>>(istream& is, Vector& v){
        v.elements.clear();
        char ch;
        int val;
        is>>ch;
        while(ch!=']'){
            is>>val;
            v.elements.push_back(val);
            is>>ch;
        }
        return is;
    }

    Vector operator+(Vector& v){
        Vector result;
        for(size_t i=0;i<elements.size();i++){
            result.elements.push_back(elements[i]+v.elements[i]);
        }
        return result;
    }

    Vector operator-(Vector& v){
        Vector result;
        for (size_t i=0;i<elements.size();i++){
            result.elements.push_back(elements[i]-v.elements[i]);
        }
        return result;
    }
};

int main(){
    Vector v1, v2;

    cout<<"Enter vector v1 in the form [10, 20, 30, ...]: ";
    cin>>v1;
    cout<<"Enter vector v2 in the form [10, 20, 30, ...]: ";
    cin>>v2;

    // cout<< "v1 = " << v1 << endl;
    // cout << "v2 = " << v2 << endl;

    Vector v3=v1+v2;
    cout<<"v1 + v2 = "<<v3<<endl;

    Vector v4=v1-v2;
    cout<<"v1 - v2 = "<<v4<<endl;
    return 0;
}