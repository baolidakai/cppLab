/**
 * Simple text editor emulating vim
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class document {
public:
	document() {
		insertMode = false;
		cursorRow = 0;
		cursorCol = 0;
	};
	friend ostream& operator<<(ostream& os, document& doc) {
		for (vector<string>::iterator it = doc.lines.begin(); it != doc.lines.end(); it++) {
			os << *it << endl;
		}
		return os;
	}
	void moveCursorUp() {
		// Move the cursor if possible
	}
private:
	vector<string> lines;
	bool insertMode;
	int cursorRow, cursorCol;
};

int main() {
	document doc = document();
	cout << doc << endl;
	return 0;
}
