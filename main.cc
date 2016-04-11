#include <iostream>
#include <string>
using namespace std;

class myFunctor {
public:
	void operator() (const string& str) const;
};

void myFunctor::operator() (const string& str) const {
	cout << str << endl;
}

int main() {
	myFunctor functor;
	functor("100");
	return 0;
}
