/**
 * Using the generate_n algorithm, the rand function, and a back_insert_iterator,
 * show how to populate a vector with a specified number of random values.
 * Then use accumulate to compute the average of the range.
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int randomNumber() {
	return rand() % 10;
}

int main() {
	vector<int> myVector;
	generate_n(back_inserter(myVector), 10, randomNumber);
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
