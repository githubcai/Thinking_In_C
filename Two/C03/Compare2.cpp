#include <cassert>
#include <string>
using namespace std;

int main(){
    string first("This is a day that will live in infamy");
    string second("I don't believe that this is what I signed up for");

    assert(first.compare(1, 7, second, 22, 7)==0);
    assert(first.compare(1, 9, second, 22, 9)<0);
}
