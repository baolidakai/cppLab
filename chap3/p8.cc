/**
 * Implementation of
 * 8. Write a function hasHexLetters that accepts an int and returns whether or not that integer's haxadecimal representation contains letters.
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool hasHexLetters(int value) {
	stringstream ss;
	ss << hex << value;
	int res;
	char remaining;
	// Contains letters iff cannot extract an integer or leave something behind
	return !(ss >> dec >> res) || (ss >> remaining);
}

bool exactHasHexLetters(int value) {
	// Naive for loop algorithm
	while (value != 0) {
		if (value % 16 > 9) {
			return true;
		}
		value /= 16;
	}
	return false;
}

int main() {
	for (int i = 0; i < 1000; i++) {
		if (hasHexLetters(i) != exactHasHexLetters(i)) {
			cout << "Different result for i = " << i << endl;
		}
	}
	return 0;
}
