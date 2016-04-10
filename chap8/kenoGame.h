#include <vector>
#include <set>
using namespace std;
#ifndef Keno_Included
#define Keno_Included
class kenoGame {
public:
	//kenoGame();

	void addNumber(int value);
	size_t numChosen();

	size_t numWinners(vector<int>& values);
private:
	set<int> guessed;
	bool hitted(int value); // returns true if value is in guessed
};
#endif
