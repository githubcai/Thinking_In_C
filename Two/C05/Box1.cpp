#include <iostream>
using namespace std;

template<class T>
class Box;

template<class T>
Box<T> operator+(const Box<T>&, cosnt Box<T>&);

template<class T>
ostream& operator<<(ostream&, const Box<T>&);

template<class T>
class Box{
    T t;
public:
    Box()
};
