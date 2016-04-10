/**
 * Show how to use a combination of copy, istreambuf_iterator, and ostreambuf_iterator to open
 * a file and prints its contents to cout.
 */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream input("words.txt");
	copy(istreambuf_iterator<char>(input), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
	return 0;
}
