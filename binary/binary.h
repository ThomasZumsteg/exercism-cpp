#pragma once

#include <string>
#include <cmath>

namespace binary {
	using namespace std;

	int convert(string strNum);
}

int binary::convert(std::string strNum) {
	/* Converts a binary to decimal */
	int nNum = 0;
	// Reverse step through every letter, if it's 1 add 2^(position)
	// Otherwise ignore
	for (auto it = strNum.crbegin(); it != strNum.crend(); it++){
		nNum += (*it == '1') ? (int)pow(2, it - strNum.crbegin()) : 0;
	}
	return nNum;
}