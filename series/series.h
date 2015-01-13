#pragma once

#include <string>
#include <vector>

namespace series {
	using namespace std;

	vector<int> digits(string strDigits);

	vector<vector<int>> slice(string strDigits, int nSliceSize);
}

//series.cpp

//#include "series.h"
using namespace std;

vector<int> series::digits(string strDigits) {
	/* The digits represented in a string */
	vector < int > vnDigits;
	for (auto it : strDigits)
		vnDigits.push_back(static_cast<int>(it - '0'));
	return vnDigits;
}

vector<vector<int>> series::slice(string strDigits, int nSliceSize) {
	/* Slices digits into ordered groups of a given size */
	if (nSliceSize <= 0 || (int)strDigits.length() < nSliceSize)
		throw domain_error("Slice size must be between 1 and the number of digits");
	vector<vector<int>> vvnSlice;
	vector<int> vnDigits = digits(strDigits);
	// Vector subtraction (it - 1) is apparently not a thing
	for (auto it = vnDigits.begin(); it + (nSliceSize - 1) != vnDigits.end(); it++) {
		vvnSlice.push_back(vector<int>(it, it + nSliceSize));
	}
	return vvnSlice;
}