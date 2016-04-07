/**
 * Implementation of
 * 9. Using X Macros, write a function stringToColor which takes as a parameter a string and returns the Color
 * object whose name exactly matches the input string.
 * e.g. stringToColor("Green") returns Green
 * stringToColor("Olive") returns NOT_A_COLOR
 */
#include <iostream>
#include <string>
using namespace std;

enum Color {
#define COLOR(c) c,
#include "color.h"
#undef COLOR
	NOT_A_COLOR,
};

Color stringToColor(string input) {
#define COLOR(c) if (input == #c) return c;
#include "color.h"
#undef COLOR
	return NOT_A_COLOR;
}

int main() {
	cout << boolalpha << (stringToColor("Green") == Green) << endl;
	cout << boolalpha << (stringToColor("GReen") == Green) << endl;
	cout << boolalpha << (stringToColor("GReen") == NOT_A_COLOR) << endl;
	cout << boolalpha << (stringToColor("Cyan") == NOT_A_COLOR) << endl;
	return 0;
}
