#include <string>
#include <cassert>
using namespace std;

int main(){
	string s1("This ");
	string s2("That ");
	string s3("The other ");

	s1 = s1 + s2;
	assert(s1=="This That ");
	s1 += s3;
	assert(s1=="This That The other ");
	
	s1 += s3 + s3[4] + "ooh lala";
	assert(s1=="This That The other The other oooh lala");
}
