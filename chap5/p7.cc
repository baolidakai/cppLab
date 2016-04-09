/**
 * 7. Implement a ring buffer supporting
 * 1) Rotate the ring clocksie
 * 2) Rotate the ring counterclockwise
 * 3) Read the value at the cursor
 * 4) Write the value at the cursor
 *
 * Use a deque to maintain the ring cursor
 * The first element is the element under the cursor, and the rest of the elements
 * are the elements in the ring buffer formed by walking clockwise around the ring buffer.
 */
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
using namespace std;

class ringBuffer {
public:
	ringBuffer(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++) {
			values.push_back(*it);
		}
		size = nums.size();
	}

	void cursorClockwise() {
		// Rotate the ring buffer clockwisely
		values.push_back(values.front());
		values.pop_front();
	}

	void cursorCounterClockwise() {
		// Rotate the ring buffer counterclockwisely
		values.push_front(values.back());
		values.pop_back();
	}

	int cursorRead() {
		return values.front();
	}

	void cursorWrite(int newElement) {
		values[0] = newElement;
	}


	friend ostream& operator<<(ostream& os, ringBuffer& rb) {
		for (size_t i = 0; i < rb.size; i++) {
			os << rb.values[i] << " ";
		}
		return os;
	}

private:
	deque<int> values;
	int size;
};

int main() {
	vector<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back(rand() % 100);
	}
	ringBuffer rb = ringBuffer(nums);
	cout << rb << endl;
	rb.cursorClockwise();
	cout << rb << endl;
	rb.cursorCounterClockwise();
	cout << rb << endl;
	cout << "The number under the current cursor is " << rb.cursorRead() << endl;
	rb.cursorWrite(100);
	cout << "The number under the current cursor is " << rb.cursorRead() << endl;
	cout << rb << endl;
	return 0;
}
