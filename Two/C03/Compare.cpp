#include <cassert>
#include <string>
using namespace std;

int main(){
    string first("This");
    string second("That");
    assert(first.compare(first)==0);
    assert(second.compare(second)==0);

    assert(first.compare(second)>0);
    assert(second.compare(first)<0);
    first.swap(second);
    assert(first.compare(second)<0);
    assert(second.compare(first)>0);
}
