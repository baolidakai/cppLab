#include <map>
#include <string>
using namespace std;
#include "groceryList.h"

/**
 * Implementation of the groceryList class
 */
groceryList::groceryList() {
	// Sets the grocery list to contain no items
}

void groceryList::addItem(string quantity, string item) {
	items[item] = quantity;
}

void groceryList::removeItem(string item) {
	items.erase(item);
}

string groceryList::itemQuantity(string item) {
	if (items.find(item) != items.end()) {
		return items[item];
	} else {
		return "";
	}
}

bool groceryList::itemExists(string item) {
	return items.find(item) != items.end();
}
