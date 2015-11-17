#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main(){
    ifstream in("StreamIt.cpp");
    assure(in, "SteamIt.cpp");
    istream_iterator<string> begin(in), end;
    ostream_iterator<string> out(cout, "\n");
    vector<string> vs;
    copy(begin, end, back_inserter(vs));
    copy(vs.begin(), vs.end(), out);
    *out++ = vs[0];
    *out++ = "That's all, folks!";
}
