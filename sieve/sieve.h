#pragma once

#include <vector>

namespace sieve {
	using namespace std;

	vector<int> primes(int nSize) {
		/* Sieve all primes smaller then some value */
		// Uses 2x the memeory since only odd numbers are tested
		vector<bool> vbSieve(nSize, true);
		vector<int> vnPrimes{2};
		for (int i = 3; i < nSize; i += 2){
			if (vbSieve[i]){
				vnPrimes.push_back(i);
				for (int j = i*i; j < nSize; j += i)
					vbSieve[j] = false;
			}
		}
		return vnPrimes;
	}
}