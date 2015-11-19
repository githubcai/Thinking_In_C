#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

template<class CharT>
charT strTolower(charT c){
    return tolower(c);
}

int main(){
    string s("LOWER");
    transform(s.begin(), s.end(), s.begin(), &strTolower<char>);
    cout << s << endl;
}
