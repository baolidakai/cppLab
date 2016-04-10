/**
 * Write a function invertMap that accepts map<string, string> and returns a multimap<string, string>
 * where each (key, value) in the source map is represented by (value, key) in the generated multimap.
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

multimap<string, string> invertMap(map<string, string> records) {
	multimap<string, string> rtn;
	for (map<string, string>::iterator it = records.begin(); it != records.end(); it++) {
		rtn.insert(make_pair(it->second, it->first));
	}
	return rtn;
}

int main() {
	map<string, string> records;
	records["hello"] = "world";
	records["bowen"] = "world";
	records["hehe"] = "hello";
	records["best"] = "person";
	multimap<string, string> invertRecords = invertMap(records);
	for (multimap<string, string>::iterator it = invertRecords.begin(); it != invertRecords.end(); it++) {
		cout << "Key: " << it->first << ", value: " << it->second << endl;
	}
	return 0;
}
