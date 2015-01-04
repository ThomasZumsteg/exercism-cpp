#pragma once

#include <map>
#include <vector>

namespace etl {
    /* Transfoms a old format to a new format */
    using namespace std;
    
    map<char, int> transform(map<int,vector<char>> mapOld) {
        /* Transforms map<int, vector<char>> to map<char, int> */
        map<char, int> mapNew;
        for(auto pairOld: mapOld) {
            // pairOld is (key, value)
            for(auto listOld: pairOld.second) {
                mapNew[tolower(listOld)] = pairOld.first;
            }
        }
        return mapNew;
    }
}