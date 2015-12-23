#include <iostream>
#include "zthread/SynchronousExecutor.h"
#include "LiftOff.h"
using namespace std;
using namespace ZThread;

int main(){
	try{
		SynchronousExecutor executor;
		for(int i = 0; i < 5; i++){
			executor.execute(new LiftOff(10, i));
		}
	}catch(Synchronization_Exception& e){
		cerr << e.what() << endl;
	}
}
