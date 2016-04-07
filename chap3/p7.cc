/**
 * Implementation of
 * 7. Using the code for GetInteger and the boolalpha stream manipulator, write a function GetBoolean that waits for the user to enter "true" or "false" and returns the corresponding boolean value.
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string GetLine() {
	string rtn;
	getline(cin, rtn);
	return rtn;
}

bool GetBoolean() {
	while (true) {
		string input = GetLine();
		bool rtn;
		stringstream ss;
		char remaining;
		ss << input;
		if (ss >> boolalpha >> rtn) {
			if (ss >> remaining) {
				cout << "Invalid character " << remaining << endl;
			} else {
				return rtn;
			}
		} else {
			cout << "Please retry!" << endl;
		}
	}
}

int main() {
	bool res = GetBoolean();
	cout << "You entered " << boolalpha << res << endl;
	return 0;
}
