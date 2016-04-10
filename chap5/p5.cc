/**
 * 5. Write a function called LinesFromFile which takes in a string containing a filename and
 * returns a vector<string> containing all the lines of text in the file in the order in which they appear.
 * If the file does not exist, you can return an empty vector.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<string> linesFromFile(string filename) {
	vector<string> rtn;
	ifstream input;
	input.open(filename.c_str());
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			rtn.push_back(line);
		}
	}
	return rtn;
}

int main() {
	vector<string> lines = linesFromFile("helloWorld.txt");
	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++) {
		cout << (*it) << endl;
	}
	return 0;
}
