#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H
#include "../require.h"
#include <iostream>
#include <set>
#include <string>

class AutoCounter{
	static int count;
	int id;
	class CleanupCheck{
		std::set<AutoCounter*> trace;
	public:
		void add(AutoCounter* ap){
			trace.insert(ap);
		}
		void remove(AutoCounter* ap){
			require(trace.erase(ap)==1, "Attempt to delete AutoCounter twice");
		}
		~CleanupCheck(){
			std::cout << "~CleanupCheck()" << std::endl;
			require(trace.size()==0, "All AutoCounter objects not cleaned up");
		}
	};
	static CleanupCheck verifier;
	AutoCounter() : id(count++){
		verifier.add(this);
		std::cout << "created[" << id << "]" << std::endl;
	}
	AutoCounter(const AutoCounter&);
	void operator=(const AutoCounter&);
public:
	static AutoCounter* create(){
		return new AutoCounter();
	}
	~AutoCounter(){
		std::cout << "destroying[" << id << "]" << std::endl;
		verifier.remove(this);
	}
	friend std::ostream& operator<<(std::ostream& os, const AutoCounter& ac){
		return os << "AutoCounter " << ac.id;
	}
	friend std::ostream& operator<<(std::ostream& os, const AutoCounter* ac){
		return os << "AutoCounter " << ac->id;
	}
};

#endif //AUTOCOUNTER_H
