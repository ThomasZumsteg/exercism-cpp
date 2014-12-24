#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <string>
#include <sstream>

namespace beer {
	/* Sings the beer song (n bottle(s) of beer on the wall) */
	using namespace std;

	string verse(int nVerse) {
		/* Sings a verse of the beer song */
		switch (nVerse) {
		// Lines with 0 and 1 bottles are special cases
		case 0:
			return "No more bottles of beer on the wall, no more bottles of beer.\n"
				"Go to the store and buy some more, 99 bottles of beer on the wall.\n";
		case 1:
			return "1 bottle of beer on the wall, 1 bottle of beer.\n"
				"Take it down and pass it around, no more bottles of beer on the wall.\n";
		case 2:
			// Handles the singular of bottle...
			return "2 bottles of beer on the wall, 2 bottles of beer.\n"
				"Take one down and pass it around, 1 bottle of beer on the wall.\n";
		}
		stringstream ssVerse;
		ssVerse << nVerse << " bottles of beer on the wall, " << nVerse << " bottles of beer.\n";
		ssVerse << "Take one down and pass it around, " << nVerse - 1 << " bottles of beer on the wall.\n";
		return ssVerse.str();
	}

	string sing(int nStart, int nStop) {
		/* Sings the beer song for a range of numbers*/
		string strSong;
		for (int iii = nStart; iii >= nStop; iii--)
			strSong += verse(iii) + "\n";
		strSong.pop_back();
		return strSong;
	}

	string sing(int nStart) {
		/* Sings the beer song from a starting point*/
		return sing(nStart, 0);
	}
}

#endif