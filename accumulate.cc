/**
 * Program to compute the average of user input
 */
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <numeric>
//#include <algorithm>
using namespace std;

string getLine() {
	string rtn;
	getline(cin, rtn);
	return rtn;
}

int getInteger(string prompt = "Enter an integer: ") {
	int rtn;
	stringstream ss;
	cout << prompt;
	ss << getLine();
	ss >> rtn;
	return rtn;
}

int main() {
	int size = getInteger("Enter the size: ");
	multiset<int> nums;
	for (int i = 0; i < size; i++) {
		nums.insert(getInteger());
	}
	cout << accumulate(nums.begin(), nums.end(), 0.0) / nums.size() << endl;
	return 0;
}
