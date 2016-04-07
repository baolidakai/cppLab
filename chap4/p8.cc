/**
 * Implementation of
 * 8. Modify the earlier definition of enum Color such that after all the colors defined in color.h,
 * there is a special value, NOT_A_COLOR, that specifies a nonexistent color.
 */
#include <iostream>
using namespace std;

#define COLOR(c) c,
enum Color {
#include "color.h"
	UNK,
};
#undef COLOR

int main() {
	Color y = YELLOW;
	cout << y << endl;
	return 0;
}
