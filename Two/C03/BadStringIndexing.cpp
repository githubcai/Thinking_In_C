#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s("1234");
    try{
        s.at(5);   
    }catch(exception& e){
        cerr << e.what() << endl;
    }
}
