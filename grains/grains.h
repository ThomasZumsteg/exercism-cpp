#pragma once

#include <cmath>

namespace grains {
    /* Counts grains on a chess board */
    using namespace std;
    
    unsigned long long square(int nSquare) {
        /* The number of grains on a square of a chess board */
        return pow(2, nSquare - 1);
    }
    
    unsigned long long total() {
        /* Grain used on all squares */
        // See: http://en.wikipedia.org/wiki/Geometric_progression#Geometric_series
        return square(65) - 1;
    }
}