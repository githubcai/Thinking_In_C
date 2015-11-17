#include <sstream>
#include "FileEditor.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]){
    FileEditor file;
    if(argc>1){
        file.open(argv[1]);
    }else{
        file.open("FEditTest.cpp");
    }

    int i=1;
    FileEditor::iterator w=file.begin();
    while(w!=file.end()){
        ostringstream ss;
        ss << i++;
        *w = ss.str() + ": " + *w;
        ++w;
    }

    file.write();
}
