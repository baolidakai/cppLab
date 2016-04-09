/**
 * 4. How do you remove the first element from a vector? From a deque?
 * Answer: erase and pop_front
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i);
	}
	myVector.erase(myVector.begin());
	for (size_t i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
	cout << endl;
	deque<int> myDeque;
	for (int i = 0; i < 10; i++) {
		myDeque.push_back(i);
	}
	myDeque.pop_front();
	for (size_t i = 0; i < myDeque.size(); i++) {
		cout << myDeque[i] << " ";
	}
	cout << endl;
	return 0;
}
