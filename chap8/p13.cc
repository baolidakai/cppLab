#include "kenoGame.h"
#include <iostream>
using namespace std;

int main() {
	kenoGame kg;
	vector<int> values;
	for (int i = 0; i < 5; i++) {
		kg.addNumber(i);
		values.push_back(i + 2);
	}
	cout << kg.numChosen() << endl;
	cout << kg.numWinners(values) << endl;
	return 0;
}
