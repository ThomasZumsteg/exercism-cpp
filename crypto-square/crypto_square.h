#pragma once

#include <string>
#include <cmath>
#include <vector>

namespace crypto_square {
	class cipher;
}

// crypto_square.cpp
//#include "crypto_square.h"

using namespace std;

class crypto_square::cipher {
	/* A square cipher class */
private:
	string m_strNormText;
public:
	cipher(string strText) {
		// Keep only letters and numbers
		for (auto it : strText) {
			if (isalnum(it))
				m_strNormText += tolower(it);
		}
	}

	string normalize_plain_text() {	return m_strNormText; }

	// Smallest square number that will hold all the characters
	unsigned int size() { return static_cast<unsigned int>(sqrt(m_strNormText.size()-1)+1); }

	vector<string> plain_text_segments() {
		/* Cuts the plain text into segments */
		int nLength = (int)size();
		vector<string> vstrSquare;
		for (int i = 0; i < (int)m_strNormText.size(); i += nLength){
			vstrSquare.push_back(m_strNormText.substr(i, nLength));
		}
		return vstrSquare;
	}

	string cipher_text() {
		/* Implements cipher */
		string strCipherText;
		for (int i = 0; i < (int)size(); i++) {
			for (int j = i; j < (int)m_strNormText.size(); j += size()) {
				strCipherText += m_strNormText[j];
			}
		}
		return strCipherText;
	}

	string normalized_cipher_text() {
		/* Splits the cipher text into evenly sized words */
		string strCipherText = cipher_text();
		string strNormCipherText;
		for (int i = 0; i < (int)strCipherText.size(); i += size())
			strNormCipherText += strCipherText.substr(i, size()) + " ";
		// CHOMP
		strNormCipherText.pop_back();
		return strNormCipherText;
	}
};