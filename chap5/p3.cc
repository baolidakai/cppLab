/**
 * 3. How do you tell how many elements are in a vector? In a deque?
 * Answer: size
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	vector<int> myVector(10, 1);
	myVector.resize(5);
	myVector.resize(15, 2);
	deque<int> myDeque(10, 2);
	cout << "The size of the vector is " << myVector.size() << endl;
	cout << "The size of the deque is " << myDeque.size() << endl;
	return 0;
}
