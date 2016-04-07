/**
 * Implementation of
 * 10. Let COLOR: all of the colors are prefaced with the identifier eColor_.
 */
#include <iostream>
#include <string>
using namespace std;

enum Color {
#define COLOR(c) eColor_##c,
#include "color.h"
#undef COLOR
};

int main() {
	Color a = eColor_Blue;
	Color b = eColor_Red;
	return 0;
}
