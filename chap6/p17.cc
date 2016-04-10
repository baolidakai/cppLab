/**
 * Write a function printMatchingPrefixes that accepts a set<string> and a string containing a prefix
 * and prints out all of the entries of the set that begin with that prefix.
 * Only need to check every between prefix + "a" and prefix + "z"
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

void printMatchingPrefixes(set<string>& words, string prefix) {
	for (set<string>::iterator it = words.lower_bound(prefix); it != words.upper_bound(prefix + "z"); it++) {
		cout << *it << endl;
	}
}

int main() {
	set<string> words;
	words.insert("a");
	words.insert("aa");
	words.insert("ab");
	words.insert("ac");
	words.insert("az");
	words.insert("b");
	words.insert("b0");
	words.insert("B0");
	words.insert("b0b");
	words.insert("bZb");
	printMatchingPrefixes(words, "b");
	return 0;
}
