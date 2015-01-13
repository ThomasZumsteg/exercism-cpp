#pragma once

#include <vector>
#include <cmath>

namespace prime {
	/* Finds prime numbers */
	using namespace std;

	bool isPrime(int nNum, vector<int> vnPrimes);

	int nth(int nNth);
}

int prime::nth(int nNth) {
	/* Returns the Nth prime number */
	if (nNth <= 0)
		throw domain_error("Must be a positive non-zero number");
	vector<int> vnPrimes{ 2 };
	for (int i = 3; vnPrimes.size() < (unsigned int)nNth; i += 2) {
		if (prime::isPrime(i, vnPrimes))
			vnPrimes.push_back(i);
	}
	// Return the last one found (the nth!)
	return vnPrimes.back();
}

bool prime::isPrime(int nNum, std::vector<int> vnPrimes) {
	/* Tests if a number is evenly divisable by any prime numbers */
	// vnPrimes needs to be an order accending list of prime numbers, starting from 2
	int nLimit = static_cast<int>(sqrt(nNum));
	for (auto nPrime : vnPrimes) {
		// Only need to check numbers up to sqrt(nNum)
		if (nLimit < nPrime) break;
		if (nNum % nPrime == 0) return false;
	}
	return true;
}
