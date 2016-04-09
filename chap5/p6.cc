/**
 * 6. Update the code for the sorting program so that it sorts elements in descending order instead of ascending order.
 */
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void printVector(vector<int>& nums);
void swap(int& i, int& j);
void selectionSort(vector<int>& nums);
vector<int> insertionSort(vector<int>& nums);

int main() {
	vector<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back((rand() % 100));
	}
	printVector(nums);
	selectionSort(nums);
	cout << "After selection sort:" << endl;
	printVector(nums);
	nums.clear();
	for (int i = 0; i < 10; i++) {
		nums.push_back((rand() % 100));
	}
	printVector(nums);
	vector<int> sortedNums = insertionSort(nums);
	cout << "After insertion sort:" << endl;
	printVector(sortedNums);
	return 0;
}

void printVector(vector<int>& nums) {
	for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

void swap(int& i, int& j) {
	int tmp = i;
	i = j;
	j = tmp;
}

void selectionSort(vector<int>& nums) {
	for (size_t i = 0; i < nums.size(); i++) {
		// Find the maximum element after i inclusively
		// Swap i with that element
		size_t maxIdx = i;
		for (size_t j = i; j < nums.size(); j++) {
			if (nums[j] > nums[maxIdx]) {
				maxIdx = j;
			}
		}
		swap(nums[maxIdx], nums[i]);
	}
}

vector<int> insertionSort(vector<int>& nums) {
	vector<int> rtn;
	for (size_t i = 0; i < nums.size(); i++) {
		// Find the location to sort
		size_t insertIdx = i;
		for (size_t j = 0; j < i; j++) {
			if (rtn[j] < nums[i]) {
				insertIdx = j;
				break;
			}
		}
		rtn.insert(rtn.begin() + insertIdx, nums[i]);
	}
	return rtn;
}
