#include "TStack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class X{
public:
    virtual ~X(){
        cout << "~X" << endl;
    }
};

int main(int argc, char* argv[]){
    requireArgs(argc, 1);
    ifstream in(argv[1]);
    assure(in, argv[1]);
    Stack<string> textlines;
    string line;
    while(getline(in, line)){
        textlines.push(new string(line));
    }
    string* s;
    for(int i=0;i<10;i++){
        if((s=(string*)textlines.pop())==0){
            break;
        }
        cout << *s << endl;
        delete s;
    }

    Stack<X> xx;
    for(int j=0;j<10;j++){
        xx.push(new X);
    }
}
