#ifndef GroceryList_Included
#define GroceryList_Included
#include <string>
#include <map>
using namespace std;
class groceryList {
public:
	groceryList();

	void addItem(string quantity, string item);
	void removeItem(string item);

	string itemQuantity(string item);
	bool itemExists(string item);
private:
	map<string, string> items;
};
#endif
