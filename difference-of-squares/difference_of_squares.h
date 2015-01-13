#pragma once

#include <cmath>

namespace squares {
	using namespace std;
	/*
	Sequence substitutions are derived from 
	sum( f(k), 0, n) = sum( f(k+1), 0, n) - f(n+1)
	where f(k) is usually k**(n+1) to find sum(k**n)
	note: f(0) must be 0
	e.g.
	sum( k**2, 0, n) = sum((k + 1)**2, 0, n) - (n + 1)**2
					 = sum(k**2 + 2*k + 1) - (n + 1)**2
					 = sum(k**2) + 2*sum(k) + sum(1) - (n + 1)**2
					 = sum(k**2) + 2*sum(k) + (n + 1) - (n + 1)**2	[sum(1, 0, n) = n + 1]
		    2*sum(k) = (n + 1)**2 - (n + 1)
					 = n**2 + 2*n + 1 - n - 1
					 = n**2 + n
			  sum(k) = (n + 1) * n / 2								[Triangle numbers]
		   sum(k)**2 = (n + 1)**2 * n**2 / 4

	sum(k**2) is left as an exercise to the reader.
		*/

	int square_of_sums(int nNum) {
		/* Square of the the sum of numbers */
		// ((n+1)*n/2)**2
		return pow(nNum, 2) * pow(nNum + 1, 2) / 4;
	}

	int sum_of_squares(int nNum) {
		/* Sum of the square of numbers */
		// (2*n**3 + 3*n**2 + n) / 6
		return nNum * (nNum + 1) * (2 * nNum + 1) / 6;
	}

	int difference(int nNum) {
		/* Difference between the square of the sum of numbers and the sum of the square of numbers*/
		// square_of_sums - sum_of_squares
		// subtraction left as an exercise
		return nNum * (nNum + 1) * (nNum - 1 ) * ( 3 * nNum + 2) / 12;
	}
}