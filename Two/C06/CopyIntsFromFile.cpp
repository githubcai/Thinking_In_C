#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include "../require.h"
using namespace std;

bool gt15(int x){
    return 15<x;
}

int main(){
    ofstream ints("someInts.out");
    ints << "1 3 47 7 89 6";
    ints.close();
    ifstream inf("someInts.out");
    assure(inf, "someInts.out");
    remove_copy_if(istream_iterator<int>(inf), istream_iterator<int>(), ostream_iterator<int>(cout, "\n"), gt15);
}
