#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void printVector(vector<int>& data) {
	for (vector<int>::iterator it = data.begin(); it < data.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

void resizeVector(vector<int>& data, int newSize) {
	data.resize(newSize);
	printVector(data);
}

void resizeVector(vector<int>& data, int newSize, int newValue) {
	data.resize(newSize, newValue);
	printVector(data);
}

int main() {
	vector<int> myVec;
	printVector(myVec);
	resizeVector(myVec, 10);
	resizeVector(myVec, 5, 5);
	resizeVector(myVec, 10, 3);
	return 0;
}
