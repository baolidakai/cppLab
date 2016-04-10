/**
 * Implement the count algorithm for vector<int>s
 */
#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int count(vector<int>::iterator start, vector<int>::iterator stop, int element) {
	int rtn = 0;
	for (vector<int>::iterator it = start; it != stop; it++) {
		if (*it == element) {
			++rtn;
		}
	}
	return rtn;
}

int main() {
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i / 2);
	}
	cout << count(myVector.begin(), myVector.end(), 4) << endl;
	return 0;
}
