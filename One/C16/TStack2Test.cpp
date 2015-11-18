#include "TStack2.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream file("TStack2Test.cpp");
    assure(file, "TStack2Test.cpp");
    Stack<string> textlines;
    string line;
    while(getline(file, line)){
        textlines.push(new string(line));
    }
    int i=0;
    Stack<string>::Iterator it = textlines.begin();
    Stack<string>::Iterator* it2=0;
    while(it!=textlines.end()){
        cout << it->c_str() << endl;
        it++;
        if(++i==10){
            it2 = new Stack<string>::Iterator(it);
        }
    }
    cout << (*it2)->c_str() << endl;
    delete it2;
}
