#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
using namespace ZThread;

class TemporaryUnlocking{
	Mutex lock;
public:
	void f(){
		Guard<Mutex> g(lock);
		// lock is acpuired
		// ...
		{
			Guard<Mutex, UnlockedScope> h(g);
			// lock is released
			// ...
			//lock is acquired
		}
		// ...
		// lock is released
	}
};

int main(){
	TemporaryUnlocking t;
	t.f();
}
