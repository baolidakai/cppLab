#include <iostream>
using namespace std;
#define myFun(var) string var = #var;

int main() {
	myFun(hello);
	myFun(man);
	cout << hello << endl;
	cout << man << endl;
	return 0;
}
