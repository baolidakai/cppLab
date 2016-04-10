/**
 * Reads a list of numbers from the user, then prints them in sorted order.
 */
#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int getInteger(string prompt = "Enter an integer: ") {
	cout << prompt;
	string line;
	getline(cin, line);
	stringstream ss;
	ss << line;
	int rtn;
	ss >> rtn;
	return rtn;
}

int main() {
	int size = getInteger("Enter the number of elements: ");
	multiset<int> nums;
	for (int i = 0; i < size; i++) {
		nums.insert(getInteger());
	}
	for (multiset<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
