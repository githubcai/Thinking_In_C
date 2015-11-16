#include <algorithm>
#include <cassert>
#include <cstddef>
using namespace std;

int main(){
    int a[]={10, 20, 30};
    const size_t SIZE=sizeof a / sizeof a[0];
    int b[SIZE];
    copy(a, a+SIZE, b);
    for(size_t i=0;i<SIZE;++i){
        assert(a[i]==b[i]);
    }
}
