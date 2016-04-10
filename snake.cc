/**
 * Implementation of the classic game Snake
 * In the map:
 * ' ' - empty tile
 * '*' -snake body
 * '#' - wall
 * '$' -food
 * 'b' - bonus
 *
 * The AI will collect the food until either
 * 1) it crashes the wall or its own body
 * 2) it collects enough food
 *
 * Extra feature: reduce the length by 1 if eaten a special token
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <unistd.h>
using namespace std;

struct Point {
	int row, col; // A point in the grid
};

struct world {
	vector<string> map;
	int nRow, nCol;
	int score;
	deque<Point> snake;
};

void playGame(world& map);
void displayResult(world& map);
void readMap(world& map);
bool playGameOnce(world& map); // Play the game for once, return false if crashed
void displayMap(world& map);
string getLine(string message);
int hamiltonDistance(Point p1, Point p2);

const int targetScore = 10; // Target number of food collected
const int bonusPoint = 2;
const double bonusProbability = 0.5;
const char food = '$';
const char empty = ' ';
const char snake = '*';
const char wall = '#';
const char bonus = 'b';

void displayMap(world& map) {
	// Pause the game
	usleep(500000);
	system("clear");
	for (int i = 0; i < map.nRow; i++) {
		cout << map.map[i] << endl;
	}
	cout << "Score: " << map.score << endl;
}

void playGame(world& map) {
	displayMap(map);
	while (true) {
		bool success = playGameOnce(map);
		displayMap(map);
		if (!success) {
			break;
		}
	}
}

void displayResult(world& map) {
	if (map.score >= targetScore) {
		displayMap(map);
		cout << "Congratulations! You earned " << targetScore << " points!" << endl;
	} else {
		displayMap(map);
		cout << "Game over!" << endl;
	}
}

string getLine(string message = "") {
	string rtn;
	cout << message;
	getline(cin, rtn);
	return rtn;
}

void readMap(world& map) {
	while (true) {
		// Prompt the user until entered a valid map name
		string filename = getLine("Enter a filename for the map: ");
		ifstream input;
		input.open(filename.c_str());
		if (input.is_open()) {
			// Read the map
			string line;
			getline(input, line);
			stringstream ss;
			ss << line;
			ss >> map.nRow >> map.nCol;
			int snakeLength = 0;
			int foodNum = 0;
			for (int row = 0; row < map.nRow; row++) {
				// Read each line consecutively
				getline(input, line);
				cout << line << endl;
				if (line.size() == 0) {
					cout << "Insufficient number of rows!" << endl;
					continue;
				} else if (line.size() != map.nCol) {
					cout << "Incorrect number of columns!" << endl;
					continue;
				} else {
					// Check if there is any invalid input
					for (int col = 0; col < map.nCol; col++) {
						switch(line[col]) {
							case empty: case wall: case bonus:
								break;
							case food:
								++foodNum;
								break;
							case snake:
								++snakeLength;
								// Initialize the snake
								map.snake.push_back(Point {row, col});
								break;
							default:
								cout << "Invalid input: " << line[col] << endl;
							continue;
						}
					}
					map.map.push_back(line);
				}
			}
			// If there is something left, invalid map
			string remaining;
			getline(input, remaining);
			if (remaining.size() != 0) {
				cout << "Too much rows!" << endl;
				continue;
			} else if (snakeLength != 1) {
				cout << "Snake not exists or too long!" << endl;
				continue;
			} else if (foodNum != 1) {
				cout << "Food number should be 1." << endl;
				continue;
			}
			map.score = 0;
			break;
		} else {
			cout << "Invalid filename. Retry!" << endl;
		}
	}
}

bool isSafe(world& map, int row, int col) {
	return (0 <= row) && (row < map.nRow) &&
		(0 <= col) && (col < map.nCol) &&
		map.map[row][col] != '#' && map.map[row][col] != '*';
}

int hamiltonDistance(int i, int j, int k, int l) {
	return abs(i - k) + abs(j - l);
}

bool playGameOnce(world& map) {
	// Get the head of the snake
	Point head = map.snake.front();
	int headNewRow = head.row;
	int headNewCol = head.col;
	// Find the food
	int foodRow = -1, foodCol = -1;
	for (int i = 0; i < map.nRow; i++) {
		for (int j = 0; j < map.nCol; j++) {
			if (map.map[i][j] == food) {
				foodRow = i;
				foodCol = j;
				break;
			}
		}
	}
	if (foodRow == -1 || foodCol == -1) {
		cout << "No food left!" << endl;
		return false;
	}
	vector<Point> directions; // All four possible directions
	directions.push_back(Point {head.row - 1, head.col});
	directions.push_back(Point {head.row + 1, head.col});
	directions.push_back(Point {head.row, head.col - 1});
	directions.push_back(Point {head.row, head.col + 1});
	vector<Point> candidates; // Locations that are safe
	vector<Point> strongCandidates; // Locations that are safe, and get closer to the food
	int origDist = hamiltonDistance(head.row, head.col, foodRow, foodCol);
	for (vector<Point>::iterator it = directions.begin(); it != directions.end(); it++) {
		if (isSafe(map, (*it).row, (*it).col)) {
			candidates.push_back(*it);
			if (hamiltonDistance((*it).row, (*it).col, foodRow, foodCol) < origDist) {
				strongCandidates.push_back(*it);
			}
		}
	}
	if (strongCandidates.size() != 0) {
		headNewRow = strongCandidates[0].row;
		headNewCol = strongCandidates[0].col;
	} else if (candidates.size() != 0) {
		headNewRow = candidates[0].row;
		headNewCol = candidates[0].col;
	} else {
		++headNewRow;
	}
	map.snake.push_front(Point {headNewRow, headNewCol});
	if (map.map[headNewRow][headNewCol] == food) {
		++map.score;
		// Add a new food
		int candidateRow = rand() % map.nRow;
		int candidateCol = rand() % map.nCol;
		while (map.map[candidateRow][candidateCol] != empty) {
			candidateRow = rand() % map.nRow;
			candidateCol = rand() % map.nCol;
		}
		map.map[candidateRow][candidateCol] = food;
		// Add a bonus
		if ((double) rand() / RAND_MAX <= bonusProbability) {
			for (int i = 0; i < 10; i++) {
				candidateRow = rand() % map.nRow;
				candidateCol = rand() % map.nCol;
				if (map.map[candidateRow][candidateCol] == empty) {
					map.map[candidateRow][candidateCol] = bonus;
					break;
				}
			}
		}
		// No need to remove the back
	} else if (map.map[headNewRow][headNewCol] == bonus) {
		// Reduce the length by 1
		map.score += bonusPoint;
		if (map.snake.size() > 1) {
			Point back = map.snake.back();
			map.map[back.row][back.col] = empty;
			map.snake.pop_back();
		}
	} else {
		// Remove the back
		Point back = map.snake.back();
		map.map[back.row][back.col] = empty;
		map.snake.pop_back();
	}
	if (!isSafe(map, headNewRow, headNewCol)) {
		return false;
	} else {
		map.map[headNewRow][headNewCol] = snake;
		return map.score < targetScore;
	}
}

int main() {
	world map;
	// Set up the game
	readMap(map);
	// Play the game
	playGame(map);
	// Show the result
	displayResult(map);
	return 0;
}
