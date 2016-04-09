/**
 * 8. Testing the reserve function on speedup for vector insertion
 * Write a program that uses push_back to insert a large number of strings into
 * a vector and a vector with reserve and a deque
 *
 * Rewrite inserting at the front
 */
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <ctime>
using namespace std;

int main() {
	int size = 10000;
	vector<string> normalVector;
	cout << "PUSH BACK" << endl;
	clock_t begin = clock();
	for (int i = 0; i < size; i++) {
		normalVector.push_back("Hello, world!");
	}
	clock_t end = clock();
	cout << "Normal vector: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	vector<string> reserveVector;
	begin = clock();
	reserveVector.reserve(size);
	for (int i = 0; i < size; i++) {
		reserveVector.push_back("Hello, world!");
	}
	end = clock();
	cout << "Reserved vector: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	deque<string> normalDeque;
	begin = clock();
	for (int i = 0; i < size; i++) {
		normalDeque.push_back("Hello, world!");
	}
	end = clock();
	cout << "Deque: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	normalVector.clear();
	reserveVector.clear();
	reserveVector.reserve(size);
	normalDeque.clear();
	cout << "INSERT FRONT" << endl;
	begin = clock();
	for (int i = 0; i < size; i++) {
		normalVector.insert(normalVector.begin(), "Hello, world!");
	}
	end = clock();
	cout << "Normal vector: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	begin = clock();
	for (int i = 0; i < size; i++) {
		reserveVector.insert(reserveVector.begin(), "Hello, world!");
	}
	end = clock();
	cout << "Reserved vector: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	begin = clock();
	for (int i = 0; i < size; i++) {
		normalDeque.push_front("Hello, world!");
	}
	end = clock();
	cout << "Deque: " << double(end - begin) / CLOCKS_PER_SEC << " seconds." << endl;
	return 0;
}
