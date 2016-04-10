#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 5;

int getInteger(int idx) {
	while (true) {
		cout << "Enter the " << idx + 1 << "th element: ";
		string line;
		getline(cin, line);
		stringstream ss;
		ss << line;
		int rtn;
		char remaining;
		if ((ss >> rtn) && !(ss >> remaining)) {
			return rtn;
		}
		cout << "Retry!" << endl;
	}
}

void readAndInsertionSort(vector<int>& data) {
	for (size_t i = 0; i < SIZE; i++) {
		// Insert the new element in the vector
		int curr = getInteger(i);
		// Get the index to insert before
		int insertIdx = i;
		for (size_t j = 0; j < i; j++) {
			if (data[j] >= curr) {
				insertIdx = j;
				break;
			}
		}
		data.insert(data.begin() + insertIdx, curr);
	}
}

void printVector(vector<int>& data) {
	for (vector<int>::iterator it = data.begin(); it != data.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main() {
	vector<int> data;
	readAndInsertionSort(data);
	printVector(data);
	return 0;
}
