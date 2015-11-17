#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int d[]={01.23, 92.370, 56.661, 023.230, 19.959, 1.0, 3.14159};
const int DSZ=sizeof d / sizeof *d;

int main(){
    vector<double> vb;
    transform(d, d+DSZ, back_inserter(vb), bind2nd(ptr_fun<double, double, double>(pow), 2.0));
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));
    cout << endl;
}
