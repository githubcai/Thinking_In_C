#include "zthread/GuardedClass.h"
using namespace ZThread;

class MyClass{
public:
	void func1(){}
	void func2(){}
};

int main(){
	MyClass a;
	a.func1();
	a.func2();
	GuardedClass<MyClass> b(new MyClass());
	b->func1();
	b->func2();
}
