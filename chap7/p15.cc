/**
 * Show how to use a combination of copy and iterator adapters to write the contents of an STL container to a file, where each element is stored on its own line.
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ofstream output("elements.txt");
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i);
	}
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(output, "\n"));
	return 0;
}
