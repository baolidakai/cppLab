/**
 * Implement a GroceryList class
 */
#include <iostream>
#include "groceryList.h"

int main() {
	groceryList gList;
	gList.addItem("One hundred", "eggs");
	gList.addItem("Ten pounds", "beef");
	gList.addItem("One pound", "pork");
	gList.addItem("5kg", "milk");
	gList.addItem("2.5kg", "sugar");
	gList.addItem("3kg", "sausage");
	cout << boolalpha << gList.itemExists("sugar") << endl;
	cout << boolalpha << gList.itemExists("noodle") << endl;
	cout << boolalpha << gList.itemExists("rice") << endl;
	cout << gList.itemQuantity("eggs") << endl;
	cout << gList.itemQuantity("milk") << endl;
	gList.removeItem("milk");
	cout << gList.itemQuantity("milk") << endl;
	return 0;
}
