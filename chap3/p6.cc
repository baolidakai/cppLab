/**
 * Implementation of
 * 6. Modify the code for GetInteger to create a function GetReal that reads a real number from the user.
 * How much did you need to modify to make this code work?
 *
 * It suffices to change from double to int
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

int GetInteger() {
	// Get an integer from user prompt, retry if fails
	while (true) {
		stringstream ss;
		cout << "Enter an integer: ";
		string input = GetLine();
		ss << input;
		int value;
		char remaining;
		if (ss >> value) {
			if (ss >> remaining) {
				cout << "Invalid character " << remaining << endl;
			} else {
				return value;
			}
		} else {
			cout << "Please retry! ";
		}
	}
}

int main() {
	int value = GetInteger();
	cout << "You entered " << value << endl;
	return 0;
}
