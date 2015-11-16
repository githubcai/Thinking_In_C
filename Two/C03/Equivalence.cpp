#include <iostream>
#include <string>
using namespace std;

int main(){
    string s2("That"), s1("This");
    if("That"==s2){
        cout << "A match" << endl;
    }
    if(s1!=s2.c_str()){
        cout << "No match" << endl;
    }
}
