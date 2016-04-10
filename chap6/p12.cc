/**
 * Rewrite the roll dice program so that the same number
 * must be rolled three times before the process terminates.
 * How many times do you expect this process to take when rolling twenty-sided dice?
 */
#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

const int NUM_SIDES = 20;
const int NUM_TRIALS = 1000;

int numRolls() {
	// Experiment once
	multiset<int> outcomes;
	int rtn = 0;
	while (true) {
		++rtn;
		int outcome = rand() % NUM_SIDES;
		if (outcomes.count(outcome) == 2) {
			return rtn;
		}
		outcomes.insert(outcome);
	}
}

double expectation() {
	double sum = 0;
	for (int i = 0; i < NUM_TRIALS; i++) {
		sum += numRolls();
	}
	return sum / NUM_TRIALS;
}

int main() {
	cout << "The expected number is " << expectation() << endl;
	return 0;
}
