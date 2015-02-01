#pragma once

#include <string>

namespace transcription {
	/* Changes DNA string to RNA*/
	using std::string;

	char to_rna(char chDNA) {
		/* Converts a single DNA nucleotide to RNA */
		// Nucleotide pairs, { DNA, RNA }
		switch (chDNA) {
		case 'G': return 'C';
		case 'A': return 'U';
		case 'T': return 'A';
		case 'C': return 'G';
		default: return chDNA;
		}
	}

	string to_rna(string strDNA) {
		/* Converts a string of DNA to RNA */
		string strRNA;
		for (char nucleotide : strDNA)
			strRNA += to_rna(nucleotide);
		return strRNA;
	}
}