#ifndef BOB_H
#define BOB_H

#include <string>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

namespace bob
{
	static bool isUpper(const string strInput);

	static string hey(const string strGreeting) {
		string strCleanGreeting = boost::trim_copy(strGreeting);
		if (strCleanGreeting == "")
			return "Fine. Be that way!";
		if (isUpper(strCleanGreeting))
			return "Whoa, chill out!";
		if (strCleanGreeting.back() == '?')
			return "Sure.";
		else
			return "Whatever.";
	}

	static bool isUpper(const string strInput) {
		bool bHasUpper = false;
		for (unsigned int i = 0; i < strInput.length(); i++) {
			char cLetter = strInput[i];
			if (isalpha(cLetter)) {
				if (isupper(cLetter))
					bHasUpper = true;
				else
					return false;
			}
		}
		return bHasUpper;
	}
};


#endif