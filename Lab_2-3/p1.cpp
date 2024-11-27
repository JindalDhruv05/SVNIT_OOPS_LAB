#include <iostream>
#include <string>
using namespace std;
class StringManager{
    public:
        StringManager(){
            lines=nullptr;
            n=0;
        }

        StringManager(string* input_lines, int input_size) {
            n = input_size;
            lines = new string[n];
            for (int i = 0; i < n; i++) {
                lines[i] = input_lines[i];
            }
        }
        StringManager(StringManager &other){
            n=other.n;
            lines=new string[n];
            for (int i = 0; i < n;i++){
                lines[i] = other.lines[i];
            }
        }

        ~StringManager() {
            delete[] lines;
            cout << "StringManager instance destroyed" << endl;
        }

        void readLines() {
            cout<<"Enter lines:"<<endl;
            string temp_lines[100];
            string line;
            n=0;
            while(true){
                getline(cin,line);
                if(line.empty())
                    break;
                temp_lines[n++]=line;
            }
            lines=new string[n];
            for(int i=0;i<n;i++){
                lines[i]=temp_lines[i];
            }
        }

        void checkString(string &str) {
            int count=0;
            for(int i=0;i<n;i++){
                if(lines[i]==str){
                    count++;
                }
            }
            if(count>0){
                cout<<"Line:"<<str<<endl;
                cout<<"Repeated "<<count<<" times"<<endl;
            } 
            else{
                cout<<"Not Found"<<endl;
            }
        }

    private:
        string* lines;
        int n;
};

int main(){
    StringManager arr;
    arr.readLines();

    cout<<"Enter the string to search: "<<endl;
    string s;
    getline(cin,s);
    arr.checkString(s);
    StringManager arr_copy(arr);
    return 0;
}
