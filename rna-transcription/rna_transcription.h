#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H

#include <string>
#include <map>

namespace transcription {
	/* Changes DNA string to RNA*/
	using namespace std;

	// Nucleotide pairs, { DNA, RNA }
	const map<char, char> DNA_RNA_map{ { 'G', 'C' },
	{ 'A', 'U' },
	{ 'T', 'A' },
	{ 'C', 'G' } };

	char to_rna(char chDNA) {
		/* Converts a single DNA nucleotide to RNA */
		return DNA_RNA_map.at(chDNA);
	}

	string to_rna(string strDNA) {
		/* Converts a string of DNA to RNA */
		string strRNA;
		for (char nucleotide : strDNA)
			strRNA += to_rna(nucleotide);
		return strRNA;
	}
}

#endif