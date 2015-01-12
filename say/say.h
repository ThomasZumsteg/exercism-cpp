#pragma once

#include <string>
#include <vector>
#include <map>

namespace say {
	std::string in_english(unsigned long long ullNum);
	std::string in_english(int nNum){
		/* Catches signed type errors */
		if (nNum < 0)
			throw std::domain_error("Must be a positive number");
		return in_english(static_cast<unsigned long long>(nNum));
	}

	std::string say_magnitude(int nMag);

	std::vector<int> make_magnitude(unsigned long long ullNum);
}

//say.cpp
//#include "say.h"

using namespace std;

string say::in_english(unsigned long long ullNum) {
	/* Says a number */
	if (ullNum >= 1000ULL * 1000ULL * 1000ULL * 1000ULL)
		throw domain_error("A trillion and over not supported, yet...");
	vector<int> vnMagnitude(make_magnitude(ullNum));
	// Must have a " " preceding the order of magnitude
	string strMagnitude[] = { "", " thousand" ," million", " billion", " trillion" };
	string strNum;
	for (int i = vnMagnitude.size() - 1; i >= 0; i--){
		if (vnMagnitude[i] > 0)
			strNum += (strNum.empty() ? "" : " ") + say_magnitude(vnMagnitude[i]) + strMagnitude[i];
	}
	return strNum.empty() ? "zero" : strNum;
}

string say::say_magnitude(int nMag){
	/* String representation of numbers between 0 and 999 */
	int nRemainer = nMag;
	string strMag;
	// All atomic words used for numbers
	map<int, string> mapSpecial { { 0, ""},
								  { 1, "one"},
								  { 2, "two"}, 
								  { 3, "three"}, 
								  { 4, "four"}, 
								  { 5, "five"},
								  { 6, "six"},
								  { 7, "seven"},
								  { 8, "eight"},
								  { 9, "nine"},
								  {10, "ten"},
								  {11, "eleven"},
								  {12, "twelve"},
								  {13, "Thiteen"},
								  {14, "fourteen"}, 
								  {15, "fifteen"},
								  {16, "sixteen"},
								  {17, "seventeen"},
								  {18, "eighteen"},
								  {19, "nineteen"},
								  {20, "twenty"},
								  {30, "thirty"},
								  {40, "forty"},
								  {50, "fifty"},
								  {60, "sixty"},
								  {70, "seventy"},
								  {80, "eighty"},
								  {90, "ninty"},
								};
	// Catches or skips hundereds
	if (nRemainer >= 100){
		strMag += mapSpecial[nRemainer / 100] + " hundred" + ((nRemainer % 100 == 0) ? "" : " ");
		nRemainer %= 100;
	}
	// If it's strange (teens)
	if (mapSpecial.count(nRemainer))
		strMag += mapSpecial[nRemainer];
	// If it's tens-ones
	else
		strMag += mapSpecial[((int)nRemainer / 10) * 10] + "-" + mapSpecial[nRemainer % 10];
	return strMag;
}

vector<int> say::make_magnitude(unsigned long long ullNum) {
	/* Breaks number into orders of magnitude */
	vector<int> vnMagnitude;
	unsigned long long ullRemainer = ullNum;
	while (ullRemainer > 0){
		vnMagnitude.push_back(ullRemainer % 1000);
		ullRemainer /= 1000;
	}
	return vnMagnitude;
}