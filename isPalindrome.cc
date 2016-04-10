/**
 * Determine if a string is palindromic.
 * Remove nonalphabetic characters, and ignore case
 * Utilizing the power of the STL algorithm
 */
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool notAlpha(char c) {
	return !::isalpha(c);
}

bool isPalindrome(string s) {
	// Remove nonalphabetic characters
	s.erase(remove_if(s.begin(), s.end(), notAlpha), s.end());
	// Ignore cases
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// Check if palindrome
	return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
	string s = "racecar";
	if (isPalindrome(s)) {
		cout << s << " is palindromic." << endl;
	} else {
		cout << s << " is not palindromic." << endl;
	}
	s = "Mayayalam";
	if (isPalindrome(s)) {
		cout << s << " is palindromic." << endl;
	} else {
		cout << s << " is not palindromic." << endl;
	}
	s = "Mr. Owl ate my metal worm";
	if (isPalindrome(s)) {
		cout << s << " is palindromic." << endl;
	} else {
		cout << s << " is not palindromic." << endl;
	}
	s = "Go hang a salami! I'm a lasagna hog.";
	if (isPalindrome(s)) {
		cout << s << " is palindromic." << endl;
	} else {
		cout << s << " is not palindromic." << endl;
	}
	return 0;
}
