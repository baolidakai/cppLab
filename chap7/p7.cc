/**
 * Write a function removeShortWords that accepts a vector<string> and removes all strings of length 3 or less from it.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isShortWord(string word) {
	return word.size() <= 3;
}

void removeShortWords(vector<string>& words) {
	// Remove all strings of length 3 or less
	words.erase(remove_if(words.begin(), words.end(), isShortWord));
}

int main() {
	vector<string> words;
	words.push_back("hello");
	words.push_back("world");
	words.push_back("wor");
	words.push_back("or");
	words.push_back("oror");
	copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	removeShortWords(words);
	copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}
