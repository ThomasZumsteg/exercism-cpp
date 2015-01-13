#pragma once

#include <boost\date_time\gregorian\gregorian.hpp>
#include <functional>

namespace meetup {
	class scheduler;
}

//meetup.cpp
//#include "meetup.h"

using namespace std;
using namespace boost::gregorian;

class meetup::scheduler {
	/* Finds natural language descriptions of dates */
private:
	typedef boost::date_time::months_of_year month;

	// Stores days according to m_vDays[weekday][nth occurance]
	vector<date> m_vDays[7];
	// Stores teenths days m_vTeenth[weekday]
	date m_vTeenth[7];

public:
	scheduler(month nMonth, int nYear) {
		// Iterates over every day in the month organizing by weekday
		for (day_iterator d(date( nYear, nMonth, 1 )); (*d).month() == nMonth; ++d ) {
			m_vDays[static_cast<int>((*d).day_of_week())].push_back((*d));
			// Catches teenths
			if (13 <= (*d).day() && (*d).day() <= 19)
				m_vTeenth[static_cast<int>((*d).day_of_week())] = (*d);
		}
	}

	// All the required functions to return the required date
	// Note: nths are 0 indexed
	date monteenth() const { return m_vTeenth[Monday]; }
	date tuesteenth() const { return m_vTeenth[Tuesday]; }
	date wednesteenth() const {return m_vTeenth[Wednesday];}
	date thursteenth() const {return m_vTeenth[Thursday];}
	date friteenth() const {return m_vTeenth[Friday];}
	date saturteenth() const {return m_vTeenth[Saturday];}
	date sunteenth() const {return m_vTeenth[Sunday];}
	date first_monday() const { return m_vDays[Monday][0]; };
	date first_tuesday() const { return m_vDays[Tuesday][0]; }
	date first_wednesday() const {return m_vDays[Wednesday][0];}
	date first_thursday() const {return m_vDays[Thursday][0];}
	date first_friday() const {return m_vDays[Friday][0];}
	date first_saturday() const {return m_vDays[Saturday][0];}
	date first_sunday() const {return m_vDays[Sunday][0];}
	date second_monday() const {return m_vDays[Monday][1];}
	date second_tuesday() const {return m_vDays[Tuesday][1];}
	date second_wednesday() const {return m_vDays[Wednesday][1];}
	date second_thursday() const {return m_vDays[Thursday][1];}
	date second_friday() const {return m_vDays[Friday][1];}
	date second_saturday() const {return m_vDays[Saturday][1];}
	date second_sunday() const {return m_vDays[Sunday][1];}
	date third_monday() const {return m_vDays[Monday][2];}
	date third_tuesday() const {return m_vDays[Tuesday][2];}
	date third_wednesday() const {return m_vDays[Wednesday][2];}
	date third_thursday() const {return m_vDays[Thursday][2];}
	date third_friday() const {return m_vDays[Friday][2];}
	date third_saturday() const {return m_vDays[Saturday][2];}
	date third_sunday() const {return m_vDays[Sunday][2];}
	date fourth_monday() const {return m_vDays[Monday][3];}
	date fourth_tuesday() const {return m_vDays[Tuesday][3];}
	date fourth_wednesday() const {return m_vDays[Wednesday][3];}
	date fourth_thursday() const {return m_vDays[Thursday][3];}
	date fourth_friday() const {return m_vDays[Friday][3];}
	date fourth_saturday() const {return m_vDays[Saturday][3];}
	date fourth_sunday() const {return m_vDays[Sunday][3];}
	date last_monday() const { return m_vDays[Monday].back(); }
	date last_tuesday() const { return m_vDays[Tuesday].back(); }
	date last_wednesday() const {return m_vDays[Wednesday].back(); }
	date last_thursday() const {return m_vDays[Thursday].back(); }
	date last_friday() const {return m_vDays[Friday].back(); }
	date last_saturday() const {return m_vDays[Saturday].back(); }
	date last_sunday() const {return m_vDays[Sunday].back(); }
};