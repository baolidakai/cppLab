// Implementation of
// 5. Using a stringstream, write a function that converts an int into a string.
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string intToString(int value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

int main() {
	int value;
	cout << "Enter an integer: ";
	cin >> value;
	string res = intToString(value);
	cout << "The integer is " << res << endl;
	return 0;
}
