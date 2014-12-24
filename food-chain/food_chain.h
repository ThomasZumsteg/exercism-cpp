#ifndef FOOD_CHAIN_H
#define FOOD_CHAIN_H

#include <string>

namespace food_chain{
	using namespace std;

	string verse(int nVerse) {
		/* Sings a verse of "I know an Old Lady Who Swallowed a Fly"
		verses are 1 to 8 inclusive */
		string aStrAnimals[] = { "",
			"fly",
			"spider",
			"bird",
			"cat",
			"dog",
			"goat",
			"cow",
			"horse"
		};
		string aStrPhrase[] = { "",
			"",
			"It wriggled and jiggled and tickled inside her.\n",
			"How absurd to swallow a bird!\n",
			"Imagine that, to swallow a cat!\n",
			"What a hog, to swallow a dog!\n",
			"Just opened her throat and swallowed a goat!\n",
			"I don't know how she swallowed a cow!\n",
			"She's dead, of course!\n"
		};
		string strVerse = "I know an old lady who swallowed a " + aStrAnimals[nVerse] + ".\n";
		strVerse += aStrPhrase[nVerse];
		if (nVerse == 8)
			return strVerse;
		for (int iii = nVerse; iii > 1; iii--) {
			strVerse += "She swallowed the " + aStrAnimals[iii] + " to catch the ";
			if (iii == 3)
				strVerse += "spider that wriggled and jiggled and tickled inside her.\n";
			else
				strVerse += aStrAnimals[iii - 1] + ".\n";
		}
		strVerse += "I don't know why she swallowed the fly. "
				    "Perhaps she'll die.\n";
		return strVerse;
	}

	string verses(int nStart, int nStop) {
		/* Sing a number of verses of "I Know an Old Lady who Swallowed a Fly" */
		string strSong = "";
		for (int iii = nStart; iii <= nStop; iii++) {
			strSong += verse(iii) + "\n";
		}
		return strSong;
	}

	string sing() {
		/* Sings all verses of "I Know an Old Lady who Swallowed a Fly" */
		return verses(1, 8);
	}
}

#endif