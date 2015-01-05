#pragma once

#include <map>
#include <vector>

namespace etl {
	using namespace std;
	const map<char, int> transform(const map<int, vector<char>> mapOld) {
		map<char, int> chrMapNew{ { 'a', 1 } };
		for (auto it : mapOld) {
			for (auto jt : it->second) {

			}
		}
		return chrMapNew;
	}
}