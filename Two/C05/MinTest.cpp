#include <cstring>
#include <iostream>
using std::strcmp;
using std::cout;
using std::endl;

template<typename T>
const T& min(const T& a, const T& b){
    return (a < b) ? a : b;
}

const char* min(const char* a, const char* b){
    return (strcmp(a, b) < 0) ? a : b;
}

double min(double x, double y){
    return (x < y) ? x : y;
}

int main(){
    const char *s2="say \"Ni~!\"", *s1="knights who";
    cout << min(1, 2) << endl;
    cout << min(1.0, 2.0) << endl;
    cout << min(1, 2.0) << endl;
    cout << min(s1, s2) << endl;
    cout << min<>(s1, s2) << endl;
}
