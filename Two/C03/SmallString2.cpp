#include <string>
#include <iostream>
using namespace std;

int main(){
	string s1("What is the sound of one clam napping?");
	string s2("Anything worth doing is worth overdoing.");
	string s3("I saw Elvis in a UFO");

	string s4(s1, 0, 8);
	cout << s4 << endl;

	string s5(s2, 15, 6);
	cout << s5 << endl;

	string s6(s3, 6, 15);
	cout << s6 << endl;

	string quoteMe = s4 + "that" + s1.substr(20, 10) + s5 + "with" + s3.substr(5, 100) + s1.substr(37, 1);
	cout << quoteMe << endl;
}
