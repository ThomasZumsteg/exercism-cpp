#pragma once

#include <string>
#include <map>

namespace scrabble_score {
	int score(std::string strWord);
}

//scrabble_score.cpp
//#include "scrabble_score.h"

using namespace std;

map<char, int> letter_score{
	// Worth 1
	{ 'A', 1 },	{ 'E', 1 },	{ 'I', 1 },	{ 'O', 1 },	{ 'U', 1 },
	{ 'L', 1 },	{ 'N', 1 },	{ 'R', 1 },	{ 'S', 1 },	{ 'T', 1 },

	// Worth 2
	{ 'D', 2 },	{ 'G', 2 },

	// Worth 3
	{ 'B', 3 },	{ 'C', 3 },	{ 'M', 3 },	{ 'P', 3 },

	// Worth 4
	{ 'F', 4 },	{ 'H', 4 },	{ 'V', 4 },	{ 'W', 4 },	{ 'Y', 4 },

	// Worth 5
	{ 'K', 5 },

	// Worth 8
	{ 'J', 8 }, { 'X', 8 },

	// Worth 10!
	{ 'Q', 10 }, { 'Z', 10 },
};

int scrabble_score::score(string strWord) {
	/* Calculate scrabble word score */
	int nWordScore = 0;
	for (auto it : strWord){
		nWordScore += letter_score[toupper(it)];
	}
	return nWordScore;
}