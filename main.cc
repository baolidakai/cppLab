#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void toLower(string& s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int main() {
	string s = "Hello, world!";
	cout << s << endl;
	toLower(s);
	cout << s << endl;
	return 0;
}
