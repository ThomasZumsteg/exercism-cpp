#pragma once

#include <string>
#include <sstream>
#include <map>

namespace raindrops {
	using namespace std;

	string convert(int nNum) {
		/* Makes sounds if number has factor */
		stringstream strRaindrop;
		// Must be sorted by sound order (lowest to highest)
		map<int, string> mSounds{ { 3, "Pling" }, { 5, "Plang" }, { 7, "Plong" } };
		for (auto pair : mSounds){
			if (nNum % pair.first == 0)
				strRaindrop << pair.second;
		}
		// If the buffer is empty
		if (strRaindrop.rdbuf()->in_avail() == 0)
			strRaindrop << nNum;
		return strRaindrop.str();
	}
}