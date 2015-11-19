#include <iostream>
#include <string>
#include "Nobloat.h"
using namespace std;

template<class StackType>
void emptyTheStack(StackType& stk){
	while(stk.size()>0){
		cout << stk.top() << endl;
		stk.pop();
	}
}

template<class T>
void emptyTheStack(Stack<T*>& stk){
	while(stk.size()>0){
		cout << *stk.top() << endl;
		stk.pop();
	}
}

int main(){
	Stack<int> s1;
	s1.push(1);
	s1.push(2);
	emptyTheStack(s1);
	Stack<int *> s2;
	int i=3, j=4;
	s2.push(&i);
	s2.push(&j);
	emptyTheStack(s2);
}
