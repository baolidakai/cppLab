/**
 * Write a function numberDuplicateEntries that accepts a map<string, string> and returns the number of duplicate values in the map
 */
#include <iostream>
#include <map>
using namespace std;

int numberDuplicateEntries(map<string, string>& records) {
	map<string, int> counter;
	int rtn = 0;
	for (map<string, string>::iterator it = records.begin(); it != records.end(); it++) {
		++counter[it->second];
	}
	for (map<string, int>::iterator it = counter.begin(); it != counter.end(); it++) {
		if (it->second > 1) {
			rtn += it->second;
		}
	}
	return rtn;
}

int main() {
	map<string, string> records;
	records["hello"] = "world";
	records["bowen"] = "world";
	records["hehe"] = "hello";
	records["best"] = "person";
	cout << numberDuplicateEntries(records) << endl;
	return 0;
}
