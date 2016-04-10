/**
 * Write a function union which takes in two set<int>s and returns their union
 */
#include <iostream>
#include <set>
using namespace std;

void setUnion(set<int>& s1, set<int>& s2, set<int>& s) {
	// Pass by reference: s = s1 + s2
	s.clear();
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		s.insert(*it);
	}
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
		s.insert(*it);
	}
}

int main() {
	set<int> s1;
	set<int> s2;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(5);
	s1.insert(8);
	s2.insert(2);
	s2.insert(3);
	s2.insert(5);
	s2.insert(7);
	s2.insert(11);
	set<int> s;
	setUnion(s1, s2, s);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
