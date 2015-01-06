#pragma once

#include <boost\date_time\gregorian\gregorian.hpp>
#include <cmath>

namespace gigasecond {
	using namespace std;

	typedef boost::gregorian::date date;
	typedef boost::gregorian::date_duration day;

	date advance(date dateNow) {
		/* Adds a gigasecond to the give date */
		// converts gigaseconds to days (3600 seconds/hour, 24 hours/day)
		return dateNow + day((long)pow(10, 9) / (3600 * 24));
	}
}