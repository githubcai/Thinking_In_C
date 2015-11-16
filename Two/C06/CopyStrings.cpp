#include <algorithm>
#include <cassert>
#include <cstddef>
#include <string>
using namespace std;

int main(){
    string a[]={"read", "my", "libs"};
    const size_t SIZE=sizeof a /sizeof a[0];
    string b[SIZE];
    copy(a, a+SIZE, b);
    assert(equal(a, a+SIZE, b));
}
