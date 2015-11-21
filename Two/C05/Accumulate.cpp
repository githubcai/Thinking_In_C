#include <iostream>
using namespace std;

template<int n, template<int> class F>
struct Accumulate{
    enum{val=Accumulate<n-1, F>::val+F<n>::val};
};

template<template<int> class F>
struct Accumulate<0, F>{
    enum{val=F<0>::};
};

template<int n>
struct Identity{
    enum{val=n};
};

template<int n>
struct Square{
    enum{val=n*n};
};

int main(){
    cout << Accumulate<4, Identity>::val << endl;
    cout << Accumulate<4, Square>::val << endl;
    cout << Accumulate<4, Cube>::val << endl;
}
