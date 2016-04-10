/**
 * Prompts the user for a filename, loads the file, then reports the frequency of each keyword in that file.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <set>
#include <sstream>
using namespace std;

void openUserFile(ifstream& fileStream);
string getFileContents(ifstream& file);
map<string, size_t> generateKeywordReport(string contents);
void loadKeywords(set<string>& keywords);

int main() {
	ifstream input;
	openUserFile(input);
	map<string, size_t> report = generateKeywordReport(getFileContents(input));
	for (map<string, size_t>::iterator it = report.begin(); it != report.end(); it++) {
		cout << "Keyword " << it->first << " occurred " << it->second << " times." << endl;
	}
	return 0;
}

void openUserFile(ifstream& input) {
	cout << "Enter filename: ";
	string filename;
	getline(cin, filename);
	input.open(filename.c_str());
	if (!input.is_open()) {
		throw "File not open!";
	}
}

string getFileContents(ifstream& file) {
	string rtn;
	string line;
	while (getline(file, line)) {
		rtn += line + "\n";
	}
	return rtn;
}

map<string, size_t> generateKeywordReport(string contents) {
	map<string, size_t> counter;
	set<string> keywords;
	loadKeywords(keywords);
	// Preprocess the string so that all punctuations become empty space
	for (size_t k = 0; k < contents.size(); k++) {
		if (ispunct(contents[k]) && contents[k] != '_') {
			contents[k] = ' ';
		}
	}
	stringstream ss;
	ss << contents;
	string word;
	while (ss >> word) {
		++counter[word];
	}
	return counter;
}

void loadKeywords(set<string>& keywords) {
	ifstream input;
	input.open("keywords.txt");
	string word;
	while (getline(input, word)) {
		keywords.insert(word);
	}
}
