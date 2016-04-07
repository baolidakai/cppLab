/**
 * Implementation of
 * 10. Write a function openFile that accepts as input an ifstream by reference and prompts the user for the name of a file. If the file can be found, openFile should return with the ifstream opened to read that file. Otherwise, openFile should print an error message and reprompt the user.
 * (Hint: input.clear() restore the input ifstream)
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openFile(ifstream& input) {
	while (true) {
		cout << "Enter the file name: ";
		string filename;
		getline(cin, filename);
		// Try to open the file
		input.open(filename.c_str());
		if (input.is_open()) {
			break;
		} else {
			input.clear();
			cout << "Please retry!" << endl;
		}
	}
}

int main() {
	ifstream input;
	openFile(input);
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}
	return 0;
}
