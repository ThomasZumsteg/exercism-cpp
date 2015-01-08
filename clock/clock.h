#pragma once

#include <string>
#include <sstream>
#include <iomanip>

namespace date_independent {
	using namespace std;
	class clock;

	bool operator== (const clock &clkOne, const clock &clkTwo);
	bool operator!= (const clock &clkOne, const clock &clkTwo);
}

// Goes in clock.cpp for any sane project
class date_independent::clock {
	/* Keeps track of time */
private:
	int m_nHour, m_nMin;
	clock(int nHour, int nMin) : m_nHour(nHour), m_nMin(nMin) {
		// Substitute for positive modulus (e.g. -10 % 3 == 2)
		// Probably a better way to do this
		while (m_nMin >= 60 || m_nMin < 0) {
			m_nHour += (m_nMin < 0) ?  -1 :  +1;
			m_nMin  += (m_nMin < 0) ? +60 : -60;
		}
		while (m_nHour >= 24 || m_nHour < 0)
			m_nHour += (m_nHour < 0) ? +24 : -24;
	}
public:
	static clock at(int nHour, int nMin) { return clock(nHour, nMin); }
	static clock at(int nHour) { return clock(nHour, 0); }

	clock plus(int nMin) const { return clock(m_nHour, m_nMin + nMin); }

	clock minus(int nMin) const { return clock(m_nHour, m_nMin - nMin);	}

	operator string() const {
		stringstream strTime;
		// Zero padded two digit displays (e.g. 03:23 or 10:01)
		strTime << setfill('0') << setw(2) << m_nHour << ":";
		strTime << setfill('0') << setw(2) << m_nMin;
		return strTime.str();
	}

	friend bool date_independent::operator== (const clock &clkOne, const clock &clkTwo);
	friend bool date_independent::operator!= (const clock &clkOne, const clock &clkTwo);
};

bool date_independent::operator== (const clock &clkOne, const clock &clkTwo) {
	return (clkOne.m_nHour == clkTwo.m_nHour) && (clkOne.m_nMin == clkTwo.m_nMin);
}

bool date_independent::operator!= (const clock &clkOne, const clock &clkTwo) {
	return !date_independent::operator== (clkOne, clkTwo);
}