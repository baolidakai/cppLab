/**
 * Write a function criticsPick that accepts a map<string, double> of (movie, rating) pairs
 * return a set<string> of the names of the top ten movies in the map.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

bool compare(const pair<string, double>& p1, const pair<string, double>& p2) {
	return p1.second > p2.second;
}

string extractKey(const pair<string, double>& tuple) {
	return tuple.first;
}

set<string> criticsPick(map<string, double>& ratings) {
	set<string> rtn;
	// Sort by rating
	vector<pair<string, double> > pairs;
	copy(ratings.begin(), ratings.end(), inserter(pairs, pairs.begin()));
	sort(pairs.begin(), pairs.end(), compare);
	transform(pairs.begin(), pairs.begin() + 10, inserter(rtn, rtn.begin()), extractKey);
	return rtn;
}

int main() {
	map<string, double> ratings;
	ratings["Titanic"] = 3;
	ratings["MI5"] = 10;
	ratings["Tomorrowland"] = 9;
	ratings["Death Note"] = 10;
	ratings["Harry Potter"] = 9.5;
	ratings["Jurassic Park"] = 10;
	ratings["Jurassic World"] = 8;
	ratings["MI4"] = 9;
	ratings["MI3"] = 8;
	ratings["MI2"] = 7;
	ratings["MI1"] = 6;
	ratings["dummy"] = 1;
	for (map<string, double>::iterator it = ratings.begin(); it != ratings.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "The top 10 movies are: ";
	set<string> picks = criticsPick(ratings);
	for (set<string>::iterator it = picks.begin(); it != picks.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
