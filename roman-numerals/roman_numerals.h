#pragma once

#include <string>
#include <map>
#include <sstream>

namespace roman {
	using namespace std;

	string convert(int nRoman) {
		/* Makes a roman representation of a number */
		// map to match 1->I, 4->IV, etc.
		// greedy algo into string stream
		int nRemaining = nRoman;
		map<int, string> mapDigit{ {   1,  "I" },
								   {   4, "IV" },
								   {   5,  "V" },
								   {   9, "IX" },
								   {  10,  "X" },
								   {  40, "XL" },
								   {  50,  "L" },
								   {  90, "XC" },
								   { 100,  "C" },
								   { 400, "CD" },
								   { 500,  "D" },
								   { 900, "CM" },
								   { 1000, "M" },
								 };
		stringstream strRoman;
		for (auto digit = mapDigit.crbegin(); digit != mapDigit.crend(); digit++){
			while (digit->first <= nRemaining){
				nRemaining -= digit->first;
				strRoman << digit->second;
			}
		}
		return strRoman.str();
	}
}