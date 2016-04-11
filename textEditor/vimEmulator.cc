/**
 * Simple text editor emulating vim
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const double WAIT_SECOND = 0.2;

class document {
public:
	document();
	document(vector<string>& initialText);
	document(ifstream& input);
	void userCommand(char c); // Read from user command, react correspondingly
private:
	vector<string> lines;
	bool insertMode;
	int cursorRow, cursorCol;
	bool moveCursorUp(); // Return false if cannot move
	bool moveCursorDown(); // Return false if cannot move
	bool moveCursorLeft(); // Return false if cannot move
	bool moveCursorRight(); // Return false if cannot move
	void moveCursorLeftmost(); // The effect of 0 in vim
	void moveCursorRightmost(); // The effect of $ in vim
	void moveForwardWord(); // The effect of w in vim
	void insert(char c);
	void printDocument();
};

int main() {
	ifstream input("helloWorld.cc");
	document doc = document(input);
	while (true) {
		cout << "Enter the command: ";
		string line;
		getline(cin, line);
		if (line.size() == 0) {
			break;
		}
		char command = line[0];
		doc.userCommand(command);
	}
	return 0;
}

document::document() {
	insertMode = false;
	cursorRow = 0;
	cursorCol = 0;
	lines.push_back(" ");
	printDocument();
}

document::document(vector<string>& initialText) {
	insertMode = false;
	cursorRow = 0;
	cursorCol = 0;
	lines = initialText;
	if (lines.size() == 0) {
		lines.push_back(" ");
	}
	if (lines[0].size() == 0) {
		lines[0] = " ";
	}
	printDocument();
}

document::document(ifstream& input) {
	// Read from a filestream
	string line;
	while (getline(input, line)) {
		if (line.size() == 0) {
			line = " ";
		}
		lines.push_back(line);
	}
	insertMode = false;
	cursorRow = 0;
	cursorCol = 0;
	if (lines.size() == 0) {
		lines.push_back(" ");
	}
	if (lines[0].size() == 0) {
		lines[0] = " ";
	}
	printDocument();
}

void document::insert(char c) {
}

bool document::moveCursorUp() {
	if (cursorRow != 0) {
		--cursorRow;
		if (lines[cursorRow].size() <= cursorCol) {
			cursorCol = lines.size() - 1;
		}
		return true;
	}
	return false;
}

bool document::moveCursorDown() {
	if (cursorRow != lines.size() - 1) {
		++cursorRow;
		if (lines[cursorRow].size() <= cursorCol) {
			cursorCol = lines.size() - 1;
		}
		return true;
	}
	return false;
}

bool document::moveCursorLeft() {
	if (cursorCol != 0) {
		--cursorCol;
		return true;
	}
	return false;
}

bool document::moveCursorRight() {
	if (cursorCol != lines[cursorRow].size() - 1) {
		++cursorCol;
		return true;
	}
	return false;
}

void document::moveCursorLeftmost() {
	cursorCol = 0;
}

void document::moveCursorRightmost() {
	cursorCol = lines[cursorRow].size() - 1;
}

void document::moveForwardWord() {
}

void document::printDocument() {
	usleep(WAIT_SECOND * 1000000);
	system("clear");
	for (size_t i = 0; i != lines.size(); i++) {
		if (i != cursorRow) {
			cout << lines[i] << endl;
		} else {
			for (size_t j = 0; j != lines[i].size(); j++) {
				if (j != cursorCol) {
					cout << lines[i][j];
				} else {
					printf("%c[4m%c%c[0m", 27, lines[i][j], 27);
				}
			}
			cout << endl;
		}
	}
}

void document::userCommand(char c) {
	if (!insertMode) {
		switch (c) {
			case 'h':
				moveCursorLeft();
				break;
			case 'j':
				moveCursorDown();
				break;
			case 'k':
				moveCursorUp();
				break;
			case 'l':
				moveCursorRight();
				break;
			case '0':
				moveCursorLeftmost();
				break;
			case '$':
				moveCursorRightmost();
				break;
			case 'w':
				moveForwardWord();
				break;
			default:
				cout << "Invalid command!" << endl;
		}
	} else {
		insert(c);
	}
	printDocument();
}
