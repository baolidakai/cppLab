/**
 * Determine if a string is palindrome by word, not by character:
 * e.g. I love I
 * Ignore non-alphabetic and non-emptyspace characters
 * Ignore cases
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool ignored(char c) {
	return !isalpha(c) && !isspace(c);
}

bool isWordPalindrome(string s) {
	// Remove non-alphabetic and non-emptyspace
	s.erase(remove_if(s.begin(), s.end(), ignored), s.end());
	// Ignore cases
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// Tokenize into words
	stringstream ss;
	ss << s;
	vector<string> words;
	copy(istream_iterator<string>(ss), istream_iterator<string>(), inserter(words, words.begin()));
	return equal(words.begin(), words.end(), words.rbegin());
}

int main() {
	cout << boolalpha << isWordPalindrome("I love! I.") << endl;
	cout << boolalpha << isWordPalindrome("she love! I.") << endl;
	return 0;
}
