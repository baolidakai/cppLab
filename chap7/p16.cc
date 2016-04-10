/**
 * Two vector<int>s are sorted in sorted order.
 * Print out the elements those vectors have in common in one line of code using set_intersection algorithm
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	cout << "v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
