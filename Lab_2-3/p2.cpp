#include<iostream>
#include<string>
using namespace std;

class StringManager{
public:
    StringManager(){
        line="";
    }

    StringManager(string &input_line) {
        line=input_line;
    }

    StringManager(StringManager &other) {
        line=other.line;
    }

    ~StringManager(){
        cout<<"StringManager instance destroyed"<<endl;
    }

    void readLine(){
        cout<<"Enter a line:"<<endl;
        getline(cin,line);
    }

    void checkAndReplaceString(string &S1,string &S2){
        size_t pos=line.find(S1);
        while(pos!=string::npos){
            line.replace(pos,S1.length(),S2);
            pos=line.find(S1,pos+S2.length());
        }
    }

    void printLine(){
        cout<<"Updated line:"<<endl;
        cout<<line<<endl;
    }

private:
    string line;
};

int main(){
    StringManager sm;
    sm.readLine();

    cout<<"Enter the string to search:"<<endl;
    string s1,s2;
    getline(cin,s1);
    cout<<"Enter the replacement string:"<<endl;
    getline(cin,s2);
    sm.checkAndReplaceString(s1,s2);
    sm.printLine();
    
    StringManager sm_copy(sm);

    return 0;
}