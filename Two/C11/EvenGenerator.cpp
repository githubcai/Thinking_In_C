#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
using namespace std;
using namespace ZThread;

class EvenGenerator : public Generator{
	unsigned int currentEvenValue;
public:
	EvenGenerator(){
		currentEvenValue = 0;
	}
	~EvenGenerator(){
		cout << "~Evengenerator" << endl;
	}
	int nextValue(){
		++currentEvenValue;
		++currentEvenValue;
		return currentEvenValue;
	}
};

int main(){
	EvenChecker::test<EvenGenerator>();
}
