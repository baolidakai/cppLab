/**
 * Simple text editor emulating vim
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <termios.h>
using namespace std;

class document {
public:
	document();
	document(vector<string>& initialText);
	document(ifstream& input);
	void userCommand(char c); // Read from user command, react correspondingly
	void saveAs(string filename);
private:
	vector<string> lines;
	bool insertMode;
	int cursorRow, cursorCol;
	int cursorColMax; // Remember the maximum value encountered
	bool moveCursorUp(); // Return false if cannot move
	bool moveCursorDown(); // Return false if cannot move
	bool moveCursorLeft(); // Return false if cannot move
	bool moveCursorRight(); // Return false if cannot move
	void moveCursorLeftmost(); // The effect of 0 in vim
	void moveCursorRightmost(); // The effect of $ in vim
	void moveForwardWord(); // The effect of w in vim
	bool moveCursorNext(); // Move cursor to the next one, if at the end line, move to the next line
	void moveCursorTop(); // The effect of gg in vim
	void moveCursorBottom(); // The effect of gg in vim
	void deleteCurrentLine(); // The effect of dd in vim
	void printDocument();
	char currentCharacter();
	void enterInsertMode(); // The effect of i
	void insert(char c); // Enter characters in insert mode
	void newLine(); // Change a newline in insert mode
};

char getch();
string redFont(const string& word);

int main() {
	cout << "\033[1;31mbold red text\033[0m\n" << endl;
	ifstream input("helloWorld.cc");
	document doc = document(input);
	while (true) {
		char command = getch();
		if (command == ':') {
			cout << ':' << flush;
			if (getch() == 'w') {
				cout << 'w' << flush;
				stringstream ss;
				while (true) {
					command = getch();
					cout << command << flush;
					ss << command;
					if (command == '\n') {
						string filename;
						ss >> filename;
						doc.saveAs(filename);
						return 0;
					}
				}
			}
		} else if (command == 'Z') {
			if (getch() == 'Z') {
				doc.saveAs("");
				return 0;
			}
		} else {
			doc.userCommand(command);
		}
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

void document::enterInsertMode() {
	insertMode = true;
}

void document::newLine() {
	string currLine = lines[cursorRow];
	lines[cursorRow] = cursorCol == 0 ? " " : currLine.substr(0, cursorCol);
	string nextLine = currLine.substr(cursorCol);
	lines.insert(lines.begin() + cursorRow + 1, nextLine);
	++cursorRow;
	cursorCol = 0;
	cursorColMax = 0;
}

void document::insert(char c) {
	if (c == 27) {
		// Escape from insert mode
		insertMode = false;
	} else if (c == 127 || c == 8) {
		// Backspace
		if (cursorCol == 0 && cursorRow != 0) {
			// Merge with the previous row
			--cursorRow;
			if (lines[cursorRow] == " ") {
				lines[cursorRow] = "";
				cursorCol = 0;
			} else {
				cursorCol = lines[cursorRow].size();
			}
			cursorColMax = cursorCol;
			lines[cursorRow] += lines[cursorRow + 1];
			lines.erase(lines.begin() + cursorRow + 1);
		} else if (cursorCol != 0) {
			lines[cursorRow].erase(lines[cursorRow].begin() + cursorCol - 1);
			--cursorCol;
			--cursorColMax;
		}
	} else {
		lines[cursorRow] = lines[cursorRow].substr(0, cursorCol) + c + lines[cursorRow].substr(cursorCol);
		++cursorCol;
		cursorColMax = cursorCol;
	}
}

bool document::moveCursorUp() {
	if (cursorRow != 0) {
		--cursorRow;
		if (lines[cursorRow].size() <= cursorColMax) {
			cursorCol = lines[cursorRow].size() - 1;
		} else {
			cursorCol = cursorColMax;
		}
		return true;
	}
	return false;
}

bool document::moveCursorDown() {
	if (cursorRow != lines.size() - 1) {
		++cursorRow;
		if (lines[cursorRow].size() <= cursorColMax) {
			cursorCol = lines[cursorRow].size() - 1;
		} else {
			cursorCol = cursorColMax;
		}
		return true;
	}
	return false;
}

bool document::moveCursorLeft() {
	if (cursorColMax != 0) {
		--cursorColMax;
	}
	if (cursorCol != 0) {
		--cursorCol;
		return true;
	}
	return false;
}

bool document::moveCursorRight() {
	++cursorColMax;
	if (cursorCol != lines[cursorRow].size() - 1) {
		++cursorCol;
		return true;
	}
	return false;
}

void document::moveCursorLeftmost() {
	cursorCol = 0;
	cursorColMax = 0;
}

void document::moveCursorRightmost() {
	cursorCol = lines[cursorRow].size() - 1;
	// Update cursorColMax to the maximum of all possible lengths
	cursorColMax = max_element(lines.begin(), lines.end(), [] (string s, string t) { return s.size() < t.size(); })->size();
}

void document::moveForwardWord() {
	// Go to the first non-empty, non-newline character after first consecutive empty/newline
	// Step 1: move to the first empty space
	while (moveCursorNext() && currentCharacter() != ' ') {}
	// Step 2: move to the next non-empty character
	while (currentCharacter() == ' ' && moveCursorNext()) {}
	cursorColMax = cursorCol;
}

bool document::moveCursorNext() {
	// If the cursor is not at the end of a line, equivalent to right
	// If at the end of a line, equivalent to Enter
	// If at the end of the file, no movement and return false
	if (cursorRow == lines.size() - 1 && cursorCol == lines[cursorRow].size() - 1) {
		return false;
	}
	if (cursorCol == lines[cursorRow].size() - 1) {
		++cursorRow;
		cursorCol = 0;
		return false;
	} else {
		++cursorCol;
	}
	return true;
}

void document::moveCursorTop() {
	cursorRow = 0;
	cursorCol = 0;
	cursorColMax = 0;
}

void document::moveCursorBottom() {
	cursorRow = lines.size() - 1;
	cursorCol = 0;
	cursorColMax = 0;
}

char document::currentCharacter() {
	return lines[cursorRow][cursorCol];
}

void document::deleteCurrentLine() {
	cursorCol = 0;
	cursorColMax = 0;
	if (cursorRow == lines.size() - 1) {
		lines.erase(lines.begin() + lines.size() - 1);
		--cursorRow;
	} else {
		lines.erase(lines.begin() + cursorRow);
	}
	if (lines.size() == 0) {
		lines.push_back(" ");
	}
}

void document::printDocument() {
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
			case 'i':
				enterInsertMode();
				break;
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
			case 'g':
				if (getch() == 'g') {
					moveCursorTop();
				}
				break;
			case 'd':
				if (getch() == 'd') {
					deleteCurrentLine();
				}
				break;
			case 'G':
				moveCursorBottom();
				break;
			default:
				cout << "Invalid command!" << endl;
		}
	} else {
		if (c != '\n') {
			insert(c);
		} else {
			cout << "newline" << endl;
			newLine();
		}
	}
	printDocument();
	if (insertMode) {
		cout << "Insert Mode" << endl;
	} else {
		cout << "Normal Mode" << endl;
	}
}

// Credit http://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
char getch() {
	char buf = 0;
	struct termios old = {0};
	if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0) perror ("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0) perror ("tcsetattr ~ICANON");
	return (buf);
}

void document::saveAs(string filename) {
	if (filename.size() == 0) {
		filename = "tmp";
	}
	ofstream output(filename.c_str());
	copy(lines.begin(), lines.end(), ostream_iterator<string>(output, "\n"));
	cout << "Saving to " << filename << endl;
}

string redFont(const string& word) {
	return "\033[1;31m" + word + "\033[0m";
}
