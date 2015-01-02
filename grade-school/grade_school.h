#pragma once

#include <string>
#include <map>
#include <vector>

namespace grade_school {
	using namespace std;
	class school;
}

class grade_school::school {
private:
	map<int, vector<string>> m_School;

public:
	string roster() {
		/* List all the grades */
		// <1,studentA>,<2,studentA,studentB>...
		return string();
	}

	void add(string strName, int nGrade) {
		/* Adds students to the school */
		m_School[nGrade].push_back(strName);
	}

	string grade(int nGrade) {
		/* Lists the students in the grade alphabetically */
		// studentA,studentB,studentC
	}
};