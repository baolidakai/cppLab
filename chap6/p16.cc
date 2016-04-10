/**
 * Write a function composeMaps that takes in two map<string, string>s and returns a map<string, string> containing their composition.
 * one[r] = s, two[s] = t => (two o one)[r] = t
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> composeMaps(map<string, string>& one, map<string, string>& two) {
	map<string, string> rtn;
	for (map<string, string>::iterator it = one.begin(); it != one.end(); it++) {
		if (two.find(it->second) != two.end()) {
			rtn[it->first] = two[it->second];
		}
	}
	return rtn;
}

int main() {
	map<string, string> one, two;
	one["r"] = "s";
	one["a"] = "b";
	one["c"] = "d";
	two["s"] = "u";
	two["d"] = "z";
	two["k"] = "l";
	map<string, string> composition = composeMaps(one, two);
	for (map<string, string>::iterator it = composition.begin(); it != composition.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
