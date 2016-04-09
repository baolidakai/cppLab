/**
 * Implementation of the game snake
 * On the map, ' ' - empty tile
 *			   '#' - wall
 *			   '$' - food
 *			   '*' - snake
 */
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int kMaxFood = 20; // Number of food to win
const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';
const string kClearCommand = "clear";
const double kTurnRate = 0.2;

struct pointT {
	int row, col;
};

struct gameT { // The map
	vector<string> world;
	int numRows, numCols;
	deque<pointT> snake;
	int dx, dy; // Velocity of snake head
	int numEaten;
};

pointT MakePoint(int row, int col) {
	// Helper function to make a point
	pointT rtn;
	rtn.row = row;
	rtn.col = col;
	return rtn;
}

string GetLine() {
	string rtn;
	getline(cin, rtn);
	return rtn;
}


void OpenUserFile(ifstream& input) {
	while (true) {
		cout << "Enter filename: ";
		string filename = GetLine();
		input.open(filename.c_str());
		if (input.is_open()) {
			break;
		}
		cout << "Sorry, I can't find the file " << filename << endl;
		input.clear();
	}
}

void LoadWorld(gameT& game, ifstream& input) {
	input >> game.numRows >> game.numCols;
	game.world.resize(game.numRows);
	input >> game.dx >> game.dy;
	string dummy;
	getline(input, dummy);
	for (int row = 0; row < game.numRows; row++) {
		getline(input, game.world[row]);
		int col = game.world[row].find(kSnakeTile);
		if (col != string::npos) {
			game.snake.push_back(MakePoint(row, col));
		}
	}
	game.numEaten = 0;
}

void InitializeGame(gameT& game) {
	srand(static_cast<unsigned int>(time(NULL)));
	ifstream input;
	OpenUserFile(input);
	LoadWorld(game, input);
}

void Pause(double waitTime) {
	clock_t startTime = clock();

	while (static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC < waitTime) {
		// Do nothing
	}
}

void PrintWorld(gameT& game) {
	system(kClearCommand.c_str());
	for (int row = 0; row < game.numRows; row++) {
		cout << game.world[row] << endl;
	}
	cout << "Food eaten: " << game.numEaten << endl;
}

void DisplayResult(gameT& game) {
	PrintWorld(game);
	if (game.numEaten == kMaxFood) {
		cout << "The snake ate enough food and wins!" << endl;
	} else {
		cout << "Oh no! The snake crashed!" << endl;
	}
}

pointT GetNextPosition(gameT& game, int dx, int dy) {
	pointT rtn = game.snake.front();
	rtn.row += dy;
	rtn.col += dx;
	return rtn;
}

bool InWorld(pointT& pt, gameT& game) {
	return pt.col >= 0 && pt.row >= 0 && pt.col < game.numCols && pt.row < game.numRows;
}

bool Crashed(pointT headPos, gameT& game) {
	return !InWorld(headPos, game) ||
		game.world[headPos.row][headPos.col] == kSnakeTile ||
		game.world[headPos.row][headPos.col] == kWallTile;
}

bool RandomChance(double probability) {
	return (rand() / (RAND_MAX + 1.0)) < probability;
}

void PerformAI(gameT& game) {
	pointT nextHead = GetNextPosition(game, game.dx, game.dy);

	if (Crashed(nextHead, game) || RandomChance(kTurnRate)) {
		int leftDx = -game.dy;
		int leftDy = game.dx;
		int rightDx = game.dy;
		int rightDy = -game.dx;
		bool canLeft = !Crashed(GetNextPosition(game, leftDx, leftDy), game);
		bool canRight = !Crashed(GetNextPosition(game, rightDx, rightDy), game);
		bool willTurnLeft = false;
		if (!canLeft && !canRight) {
			return;
		} else if (canLeft && !canRight) {
			willTurnLeft = true;
		} else if (!canLeft && canRight) {
			willTurnLeft = false;
		} else {
			willTurnLeft = RandomChance(0.5);
		}
		game.dx = willTurnLeft ? leftDx : rightDx;
		game.dy = willTurnLeft ? leftDy : rightDy;
	}
}

void PlaceFood(gameT& game) {
	while (true) {
		int row = rand() % game.numRows;
		int col = rand() % game.numCols;

		if (game.world[row][col] == kEmptyTile) {
			game.world[row][col] = kFoodTile;
			return;
		}
	}
}

bool MoveSnake(gameT& game) {
	pointT nextHead = GetNextPosition(game, game.dx, game.dy);
	if (Crashed(nextHead, game)) {
		return false;
	}
	bool isFood = (game.world[nextHead.row][nextHead.col] == kFoodTile);
	game.world[nextHead.row][nextHead.col] = kSnakeTile;
	game.snake.push_front(nextHead);
	if (!isFood) {
		game.world[game.snake.back().row][game.snake.back().col] = kEmptyTile;
		game.snake.pop_back();
	} else {
		++game.numEaten;
		PlaceFood(game);
	}
	return true;
}

void RunSimulation(gameT& game) {
	// Keep looping while we haven't eaten too much.
	while (game.numEaten < kMaxFood) {
		PrintWorld(game);
		PerformAI(game);

		if (!MoveSnake(game)) {
			break;
		}

		Pause(0.01);
	}
	DisplayResult(game);
	Pause(10);
}

int main() {
	gameT game;
	InitializeGame(game);
	RunSimulation(game);
	return 0;
}
