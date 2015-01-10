#pragma once

#include <vector>
#include <cmath>

namespace prime_factors {
	using namespace std;

	vector<int> of(int nNum);
}

//prime_factors.cpp
//#include "prime_factors.h"
using namespace std;

vector<int> prime_factors::of(int nNum) {
	/* Finds all prime factors, including repeates, of a number */

	// Twice as many lines as Python, many times faster...
	vector<int> vnFactors;
	int nRemainer = nNum;
	for (int i = 2; i <= sqrt(nNum); i++){
		while (nRemainer % i == 0){
			vnFactors.push_back(i);
			nRemainer /= i;
		}
		// Early exit
		if (nRemainer == 1)
			return vnFactors;
	}
	// Catch if nNum is square
	if (nRemainer != 1)
		vnFactors.push_back(nRemainer);
	return vnFactors;
}