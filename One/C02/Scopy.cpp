#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream in("Scopy.cpp");
	ofstream out("Scopy.out");
	string s;
	while(getline(in, s)){
		out << s << "\n";
	}
}
