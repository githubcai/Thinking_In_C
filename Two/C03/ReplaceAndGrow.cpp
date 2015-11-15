#include <cassert>
#include <string>
using namespace std;

int main(){
	string bigNews("I have been working the grave.");
	string replaceMent("yard shift.");

	bigNews.replace(bigNews.size()-1, replaceMent.size(), replaceMent);
	assert(bigNews=="I have been working the graveyard shift.");
}
