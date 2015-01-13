#pragma once

#include <vector>

namespace triangle {
	using namespace std;

	enum triangle {
		// Types of triangles
		illegal,
		equilateral,
		isosceles,
		scalene,
	};
	
	template<typename T>
	triangle kind(T nSideA, T nSideB, T nSideC) {
		/* Classifies triangles */
		vector<T> v_Triangle{ nSideA, nSideB, nSideC };
		sort(v_Triangle.begin(), v_Triangle.end());
		if (find(v_Triangle.begin(), v_Triangle.end(), 0) != v_Triangle.end())
			// No zero length edges
			throw domain_error("Triangles with zero length sides are illegal");
		if (v_Triangle[0] + v_Triangle[1] <= v_Triangle[2])
			// No base longer then the sum of the remaining two sides
			return triangle::illegal;
		if (v_Triangle[0] == v_Triangle[1] && v_Triangle[1] == v_Triangle[2])
			// All equal
			return triangle::equilateral;
		if (v_Triangle[0] == v_Triangle[1] || v_Triangle[1] == v_Triangle[2])
			// Two and only two equal
			return triangle::isosceles;
		else
			// Everything else
			return triangle::scalene;
	}
}