#pragma once

#include <string>
#include <cmath>

namespace hexadecimal{
	int convert(std::string strHex);
}

//hexadecimal.cpp
//#include "hexadecimal.h"

using namespace std;

int hexadecimal::convert(string strHex) {
	/* Converts a hexadecimal string to decimal */
	int nHex = 0;
	for (auto &it = strHex.crbegin(); it != strHex.crend(); it++){
		int nPow = (int)pow(16, it - strHex.crbegin());
		if (isalpha(*it) && (*it - 'a' <= 6))
			// a-f = (10 - 15)
			nHex += nPow * (*it - 'a' + 10);
		else if (isdigit(*it))
			// 0-9 = (0-9)
			nHex += nPow * (*it - '0');
		else
			// Non hex digits invalidate the number
			return 0;
	}
	return nHex;
}