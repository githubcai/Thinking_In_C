#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
using namespace std;

int main(){
    ostream_iterator<int> out(cout, " ");
    vector<int> v(15);
    srand(time(0));
    generate(v.begin(), v.end(), URandGen(20));
    copy(v.begin(), v.end(), out);
    cout << endl;
    transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 10));
    copy(v.begin(), v.end(), out);
    cout << endl;
}
