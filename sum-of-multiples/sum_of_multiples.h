#pragma once

#include <vector>

namespace sum_of_multiples {
	using namespace std;
	
	int to(vector<int> factors, int nNum);

	int to(int nNum) {
		/* Single arguments uses factors 3 and 5 */
		return to(vector < int > {3, 5}, nNum);
	}

	bool isFactor(vector<int> factors, int nNum);
}

// sum_of_multiples.cpp

int sum_of_multiples::to(std::vector<int> factors, int nNum) {
	/* The sum of all numbers less then a nNum that have a factor in common with factors */
	int nSum = 0;
	for (int i = 0; i < nNum; i++) {
		if (isFactor(factors, i))
			nSum += i;
	}
	return nSum;
}

bool sum_of_multiples::isFactor(std::vector<int> factors, int nNum) {
	/* True if a factor of nNum is in factors */
	for (auto it : factors) {
		if (nNum % it == 0)
			return true;
	}
	return false;
}
