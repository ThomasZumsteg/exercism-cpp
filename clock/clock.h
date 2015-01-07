#pragma once

#include <string>
#include <sstream>
#include <iomanip>

namespace date_independent {
	using namespace std;
	class clock;
}

class date_independent::clock {
private:
	int m_nHour, m_nMin;
	clock(int nHour, int nMin) : m_nHour(nHour), m_nMin(nMin) {
		m_nHour += m_nMin / 60;
		m_nMin %= 60;
		m_nHour %= 12;
	}
public:
	static clock at(int nHour, int nMin) { return clock(nHour, nMin); }
	static clock at(int nHour) { return clock(nHour, 0); }

	clock plus(int nMin) const { return clock(m_nHour, m_nMin + nMin); }

	clock minus(int nMin) const { return clock(m_nHour, m_nMin - nMin);	}

	operator string() const {
		stringstream strTime;
		strTime << setfill('0') << setw(2) << m_nHour << ":";
		strTime << setfill('0') << setw(2) << m_nMin;
		return strTime.str();
	}
};
