/**
 * Write a function biasedSort that accepts a vector<string> by reference and sorts
 * the vector lexicographically, except that if the vector contains the string "Me First,"
 * that string is always at the front of the sorted list.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

bool compare(string s1, string s2) {
	if (s1 == "Me First,") {
		return true;
	}
	if (s2 == "Me First,") {
		return false;
	}
	return s1 < s2;
}

void biasedSort(vector<string>& dictionary) {
	sort(dictionary.begin(), dictionary.end(), compare);
}

int main() {
	vector<string> dictionary;
	// Read from user prompt, only one line
	ifstream input("words.txt");
	string word;
	while (getline(input, word)) {
		dictionary.push_back(word);
	}
	copy(dictionary.begin(), dictionary.end(), ostream_iterator<string>(cout, "\n"));
	cout << endl;
	biasedSort(dictionary);
	copy(dictionary.begin(), dictionary.end(), ostream_iterator<string>(cout, "\n"));
	cout << endl;
	return 0;
}
