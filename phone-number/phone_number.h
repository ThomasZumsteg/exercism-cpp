#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>
#include <regex>

using namespace std;

class phone_number {
private:
	// Numbers in the phone number
	string m_strPhoneNumber;
public:
	phone_number(const string strPhoneNumber) {
		/* Extracts and validates the phone number*/
		string strDigits = regex_replace(strPhoneNumber, regex("\\D"), string());
		if (strDigits.length() == 10)
			m_strPhoneNumber = strDigits;
		else if (strDigits[0] == '1' && strDigits.length() == 11)
			m_strPhoneNumber = strDigits.substr(1);
		else
			m_strPhoneNumber = "0000000000";
	}

	string number() const {
		return m_strPhoneNumber;
	}

	string area_code() const {
		/* Returns the first three digits*/
		return m_strPhoneNumber.substr(0, 3);
	}

	operator string() const{
		/* Conversion to string phone number */
		return "(" + m_strPhoneNumber.substr(0,3) + ") " +
			m_strPhoneNumber.substr(3,3) + "-" + m_strPhoneNumber.substr(6);
	}
};

#endif