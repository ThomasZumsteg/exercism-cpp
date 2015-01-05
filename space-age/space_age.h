#pragma once

#include <functional>

namespace space_age {
    /* Your age on any planet */
    using namespace std;
    class space_age;
}

class space_age::space_age {
private:
    long m_nAge;
    typedef function<double ()> spaceFunc;
    spaceFunc on_any(double dRatio) {
        /* Generates functions that multiply by a ratio */
        double dYear = 31557600.0 * dRatio;
        return [=] () { return (m_nAge / dYear); };
    }
public:
    space_age(long nAge): m_nAge(nAge) {
    }
    
    long seconds() const { return m_nAge; }
    spaceFunc const on_mercury = on_any(0.2408467);
    spaceFunc const on_venus   = on_any(0.61519726);
    spaceFunc const on_earth   = on_any(1.0000000);
    spaceFunc const on_mars    = on_any(1.8808158);
    spaceFunc const on_jupiter = on_any(11.862615);
    spaceFunc const on_saturn  = on_any(29.447498);
    spaceFunc const on_uranus  = on_any(84.016846);
    spaceFunc const on_neptune = on_any(164.79132);
};