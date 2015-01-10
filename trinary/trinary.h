#pragma once

#include <string>
#include <cmath>

namespace trinary {
	using namespace std;
	int to_decimal(string strTrinary);
}

//trinary.cpp
//#include "trinary.h"

using namespace std;

int trinary::to_decimal(string strTrinary) {
	/* Coverts a trinary string to decimal */
	int nDecimal = 0;
	// Go backwards though the string
	for (auto it = strTrinary.crbegin(); it != strTrinary.crend(); it++) {
		switch (*it) {
		case '1':
			// Pointer math to do the power
			nDecimal += static_cast<int>(pow(3, it - strTrinary.crbegin()));
			break;
		case '2':
			nDecimal += 2 * static_cast<int>(pow(3, it - strTrinary.crbegin()));
			break;
		// And skip everything that's not 1 or 2 ...
		}
	}
	return nDecimal;
}