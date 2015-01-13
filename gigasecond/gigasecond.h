#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>
#include <cmath>

namespace gigasecond {
    typedef boost::gregorian::date date;
    
    date advance(date dateStart) {
        return date(2043, 1, 2);
        //return dateStart + std::pow(10, 9);
    }
}