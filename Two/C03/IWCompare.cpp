#include <cassert>
#include <iostream>
#include "iwchar_traits.h"
using namespace std;

int main(){
    iwstring wfirst = L"tHis";
    iwstring wsecond = L"ThIS";
    wcout << wfirst << endl;
    wcout << wsecond << endl;
    assert(wfirst.compare(wsecond)==0);
    assert(wfirst.find('h')==1);
    assert(wfirst.find('I')==2);
    assert(wfirst.find('X')==wstring::npos);
}
