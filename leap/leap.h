#pragma once

namespace leap {
    bool is_leap_year(int year) {
        // Year is divisible by 4
        // and not by 100 unless also divisible by 400
        return (year % 4 == 0 &&
                (year % 100 != 0 || year % 400 == 0));
    }
}