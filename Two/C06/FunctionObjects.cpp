#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;


template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& dest, UnaryFunc f){
    transform(source.begin(), source.end(), dest.begin(), f);
}

template<typename Contain1, typename Contain2, typename BinaryFunc>
void testBinary(Contain1& src1, Contain1& src2, Contain2& dest, BinaryFunc f){
    transform(src1.begin(), src1.end(), src2.begin(), dest.begin(), f);
}

#define T(EXPR) EXPR; print(r.begin(), r.end(), "After " #EXPR);
#define B(EXPR) EXPR; print(br.begin(), br.end(), "After " #EXPR);

struct BRand{
    bool operator()(){
        return rand()%2==0;
    }
};

int main(){
    const int SZ = 10;
    const int MAX = 50;
    vector<int> x(SZ), y(SZ), r(SZ);

    URandGen urg(MAX);
    srand(time(0));
    generate_n(x.begin(), SZ, urg);
    generate_n(y.begin(), SZ, urg);
    transform(y.begin(), y.end(), y.begin(), bind2nd(plus<int>(), 1));

    x[0] = y[0];
    print(x.begin(), x.end(), "x");
    print(y.begin(), y.end(), "y");
    
    T(testBinary(x, y, r, plus<int>()));
    T(testBinary(x, y, r, minus<int>()));
    T(testBinary(x, y, r, multiplies<int>()));
    T(testBinary(x, y, r, divides<int>()));
    T(testBinary(x, y, r, modulus<int>()));
    T(testUnary(x, r, negate<int>()));

    vector<bool> br(SZ);
    B(testBinary(x, y, br, equal_to<int>()));
    B(testBinary(x, y, br, not_equal_to<int>()));
    B(testBinary(x, y, br, greater<int>()));
    B(testBinary(x, y, br, less<int>()));
    B(testBinary(x, y, br, greater_equal<int>()));
    B(testBinary(x, y, br, less_equal<int>()));
    B(testBinary(x, y, br, not2(greater_equal<int>())));
    B(testBinary(x, y, br, not2(less_equal<int>())));

    vector<bool> b1(SZ), b2(SZ);
    generate_n(b1.begin(), SZ, BRand());
    generate_n(b2.begin(), SZ, BRand());
    print(b1.begin(), b1.end(), "b1");
    print(b2.begin(), b2.end(), "b2");
    B(testBinary(b1, b2, br, logical_and<int>()));    
    B(testBinary(b1, b2, br, logical_or<int>()));    
    B(testUnary(b1, br, logical_not<int>()));
    B(testUnary(b1, br, not1(logical_not<int>())));    
}
