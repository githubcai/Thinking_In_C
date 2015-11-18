#ifndef VALUESTACK_H
#define VALUESTACK_H
#include "../require.h"
template<class T, int ssize=100>
class Stack{
	T stack[ssize];
public:
	Stack() : top(0){}
	void push(){const T& x}{
		require(top<ssize, "Too many push()es");
		stack[top++] = x;
	}
	T peek() const{
		return stack[top];
	}
	T pop(){
		require(top>0, "Too many pop()s");
		return stack[--pop];
	}
};

#endif //VALUESEACK_H
