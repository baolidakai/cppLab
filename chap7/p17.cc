/**
 * Implement a function monoalphabeticSubstitutionEncrypt that accepts a source string and encrypts it with a random monoalphabetic substitution cipher.
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string monoalphabeticSubstitutionEncrypt(string source) {
	string letters = "abcdefghijklmnopqrstuvwxyz";
	random_shuffle(letters.begin(), letters.end());
	auto textToCipher = [letters](char c) { return letters[c - 'a']; };
	transform(source.begin(), source.end(), source.begin(), textToCipher);
	return source;
}

int main() {
	cout << monoalphabeticSubstitutionEncrypt("aaa") << endl;
	cout << monoalphabeticSubstitutionEncrypt("aaa") << endl;
	cout << monoalphabeticSubstitutionEncrypt("aaabbb") << endl;
	return 0;
}
