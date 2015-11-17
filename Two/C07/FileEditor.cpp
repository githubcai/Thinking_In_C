#include "FileEditor.h"
#include <fstream>
#include "../require.h"
using namespace std;

void FileEditor::open(const char* filename){
    ifstream in(filename);
    assure(in, filename);
    string line;
    while(getline(in, line)){
        push_back(line);
    }
}

void FileEditor::write(ostream& out){
    for(iterator w=begin();w!=end();w++){
        out << *w << endl;
    }
}
