/**
 * Implementation of
 * 3. Write a regular C++ function called Max that returns the larger of two int values.
 */
#include <iostream>
using namespace std;

int Max(int a, int b) {
	// Returns the maximum value
	return a > b ? a : b;
}

int main() {
	int a, b;
	cout << "Enter integer 1: ";
	cin >> a;
	cout << "Enter integer 2: ";
	cin >> b;
	cout << "The maximum of " << a << " and " << b << " is " << Max(a, b) << endl;
	return 0;
}
