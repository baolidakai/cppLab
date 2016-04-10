/**
 * Numerical simulation for the probability theory problem:
 * roll a dice with N faces repeatedly until there is duplicate
 * what is the expected number
 */
#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;

const int NUM_FACES = 6;

int numRolls() {
//	set<int> outcomes;
//	int counter = 0;
//	while (true) {
//		++counter;
//		int outcome = rand() % NUM_FACES;
//		if (outcomes.count(outcome)) {
//			return counter;
//		}
//		outcomes.insert(outcome);
//	}
	vector<int> outcomes;
	while (true) {
		int outcome = rand() % NUM_FACES;
		if (find(outcomes.begin(), outcomes.end(), outcome) != outcomes.end()) {
			return outcomes.size() + 1;
		}
		outcomes.push_back(outcome);
	}
}

double averageTrialNum(int m) {
	double sum = 0;
	for (int i = 0; i < m; i++) {
		sum += numRolls();
	}
	return sum / m;
}

int main() {
	double expectation = averageTrialNum(1000);
	cout << "The average is " << expectation << endl;
	return 0;
}
