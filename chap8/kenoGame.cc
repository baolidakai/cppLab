#include "kenoGame.h"
void kenoGame::addNumber(int value) {
	guessed.insert(value);
}

size_t kenoGame::numChosen() {
	return guessed.size();
}

size_t kenoGame::numWinners(vector<int>& values) {
	auto hitted = [this] (int value) { return this->guessed.find(value) != this->guessed.end(); };
	return count_if(values.begin(), values.end(), hitted);
}
