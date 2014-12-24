#ifndef HAMMING_H
#define HAMMING_H

#include <string>

namespace hamming {
	using namespace std;

	int compute(string strDNA_a, string strDNA_b) {
		/*Counts the differences between two strings to dna*/
		if (strDNA_a.length() != strDNA_b.length())
			throw domain_error("DNA strands need to be the same length");
		int nDistance = 0;
		for (unsigned int iii = 0; iii < strDNA_a.length(); iii++) {
			if (strDNA_a[iii] != strDNA_b[iii])
				nDistance++;
		}
		return nDistance;
	}

}

#endif