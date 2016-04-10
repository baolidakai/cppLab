/**
 * Print the average of the values in the file between 25 and 75
 * If no elements, print a message
 * distance(start, end) returns the number of elements in that range
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

bool isOutlier(double num) {
	return num < 25 || num > 75;
}

double averageInFile(string filename) {
	ifstream input(filename.c_str());
	vector<double> nums;
	copy(istream_iterator<double>(input), istream_iterator<double>(), inserter(nums, nums.begin()));
	// Remove outliers
	vector<double>::iterator it = remove_if(nums.begin(), nums.end(), isOutlier);
	// Compute the length
	int size = distance(nums.begin(), it);
	if (size == 0) {
		cout << "No such value!" << endl;
		return 0;
	}
	// Compute the sum
	double sum = accumulate(nums.begin(), it, 0.0);
	return sum / size;
}

int main() {
	cout << averageInFile("numbers.txt") << endl;
	return 0;
}
