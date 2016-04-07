/**
 * Implementation of challenge 12
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum LengthUnit {
#define DEFINE_UNIT(unitName, pmu, suffix, system) eLengthUnit_##suffix,
#include "units.h"
#undef DEFINE_UNIT
	eLengthUnit_ERROR, // Sentinal indicating that the value is invalid
};

LengthUnit SuffixStringToLengthUnit(string suffix) {
	// Read a string representation, returns the LengthUnit
	// If not exist, return eLengthUnit_ERROR
#define DEFINE_UNIT(unitName, pmu, sufstr, system) if (suffix == #sufstr) return eLengthUnit_##sufstr;
#include "units.h"
#undef DEFINE_UNIT
	return eLengthUnit_ERROR;
}

struct Length {
	double value;
	LengthUnit unit;
};

Length ReadLength() {
	// prompt the user for a double and a string
	while (true) {
		cout << "Enter the amount: ";
		string line;
		getline(cin, line);
		stringstream ss;
		ss << line;
		double value;
		if (ss >> value) {
			char remaining;
			if (ss >> remaining) {
				cout << "Invalid amount! Reenter!" << endl;
				continue;
			}
			cout << "Enter the unit: ";
			string unit;
			getline(cin, unit);
			// Check if the string corresponds to a suffix
			LengthUnit lu = SuffixStringToLengthUnit(unit);
			if (lu != eLengthUnit_ERROR) {
				Length rtn = {value, lu};
				return rtn;
			} else {
				cout << "Invalid unit! Reenter!" << endl;
			}
		} else {
			cout << "Reenter!" << endl;
		}
	}
}

string GetUnitType(Length len) {
	// return the unit system in which len occurs
	LengthUnit lu = len.unit;
#define DEFINE_UNIT(unitName, pmu, suffix, system) if (lu == eLengthUnit_##suffix) return #suffix;
#include "units.h"
#undef DEFINE_UNIT
	return "";
}

void PrintLength(Length len) {
	string unitType = GetUnitType(len);
	double value = len.value;
	string name;
#define DEFINE_UNIT(unitName, pmu, suffix, system) if (unitType == #suffix) name = #unitName;
#include "units.h"
#undef DEFINE_UNIT
	cout << value << unitType << " (" << value << " " << name << "s)" << endl;
}

Length ConvertToMeters(Length len) {
	// converts len to an equivalent length in meters
	double value = len.value;
	double newValue;
	string unitType = GetUnitType(len);
#define DEFINE_UNIT(unitName, pmu, suffix, system) if (unitType == #suffix) newValue = value * pmu;
#include "units.h"
#undef DEFINE_UNIT
	Length rtn = {newValue, eLengthUnit_m};
	return rtn;
}

int main() {
	Length len = ReadLength();
	PrintLength(len);
	cout << "Can be converted to: ";
	PrintLength(ConvertToMeters(len));
	return 0;
}
