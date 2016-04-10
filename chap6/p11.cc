/**
 * Write a function intersection that takes in two set<int>s and returns their intersection.
 */
#include <iostream>
#include <set>
using namespace std;

set<int> intersection(set<int>& s1, set<int>& s2) {
	set<int> rtn;
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		if (s2.count(*it)) {
			rtn.insert(*it);
		}
	}
	return rtn;
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
	set<int> s = intersection(s1, s2);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
