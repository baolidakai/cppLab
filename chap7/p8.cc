/**
 * Write a function distanceToOrigin that accepts a vector<double> and returns the distance from that point to the origin
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

double distanceToOrigin(vector<double> point) {
	double sumSq = inner_product(point.begin(), point.end(), point.begin(), 0);
	return sqrt(sumSq);
}

int main() {
	vector<double> point;
	point.push_back(3);
	point.push_back(4);
	cout << "The distance to origin is " << distanceToOrigin(point) << endl;
	return 0;
}
