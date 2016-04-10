/**
 * Using the nth_element algorithm, write a function that computes the median of a set of data.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

double median(vector<double>& nums) {
	if (nums.size() == 0) {
		cout << "Empty set!" << endl;
		return 0.0;
	} else if (nums.size() % 2 == 1) {
		// The exact middle element
		nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
		return nums[nums.size() / 2];
	} else {
		nth_element(nums.begin(), nums.begin() + nums.size() / 2 - 1, nums.end());
		nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
		return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
	}
}

int main() {
	cout << "Enter the numbers (separated by emptyspace): ";
	string line;
	stringstream ss;
	getline(cin, line);
	ss << line;
	vector<double> nums;
	copy(istream_iterator<double>(ss), istream_iterator<double>(), inserter(nums, nums.begin()));
	cout << "The median is " << median(nums) << endl;
	return 0;
}
