/**
 * Implementation of the naive selection sort algorithm using the STL vector
 */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int N = 5;

void getData(vector<int>& data) {
	// Get the data from user input
	for (int i = 0; i < N; i++) {
		while (true) {
			cout << "Enter the " << i + 1 << "th element: ";
			string line;
			getline(cin, line);
			stringstream ss;
			ss << line;
			int curr;
			char remaining;
			if ((ss >> curr) && !(ss >> remaining)) {
				data.push_back(curr);
				break;
			}
			cout << "Invalid input! Retry!" << endl;
		}
	}
}

void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void selectionSort(vector<int>& data) {
	// Sort the vector in place
	size_t n = data.size();
	for (size_t i = 0; i < n; i++) {
		// Find the minimum element from data[i] to end
		size_t minIdx = i;
		int minElement = data[i];
		for (size_t j = i + 1; j < n; j++) {
			if (data[j] < minElement) {
				minIdx = j;
				minElement = data[j];
			}
		}
		// Move that element to the top
		swap(data[i], data[minIdx]);
	}
}

void printVector(vector<int>& data) {
	for (vector<int>::iterator it = data.begin(); it < data.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main() {
	vector<int> data;
	getData(data);
	printVector(data);
	selectionSort(data);
	printVector(data);
	return 0;
}
