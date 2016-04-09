/**
 * 9. Implement the Vigenere cipher
 * Use deque to represent the keys
 */
#include <iostream>
#include <string>
#include <deque>
using namespace std;

string vigenereEncrypt(string text, deque<int> keys) {
	string rtn = text;
	for (int i = 0; i < text.size(); i++) {
		rtn[i] += keys.front();
		// Rotate the keys
		keys.push_back(keys.front());
		keys.pop_front();
	}
	return rtn;
}

string vigenereDecrypt(string cipher, deque<int> keys) {
	string rtn = cipher;
	for (int i = 0; i < cipher.size(); i++) {
		rtn[i] -= keys.front();
		// Rotate the keys
		keys.push_back(keys.front());
		keys.pop_front();
	}
	return rtn;
}

int main() {
	string text = "THECOOKISSAREINTHEFRIDGE";
	deque<int> keys;
	keys.push_back(1);
	keys.push_back(3);
	keys.push_back(7);
	string cipher = vigenereEncrypt(text, keys);
	cout << "The text is " << text << endl;
	cout << "The encrypted message is " << cipher << endl;
	cout << "The decrypted message is " << vigenereDecrypt(cipher, keys) << endl;
	return 0;
}
