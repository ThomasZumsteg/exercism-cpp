#pragma once

#import <string>
#import <map>
#import <vector>
#include <algorithm>

namespace grade_school {
    using namespace std;
    
    class school;
}

class grade_school::school {
private:
    map<int, vector<string>> m_school;
public:
    school() {
    }
    
    map<int, vector<string>> roster() {
        return m_school;
    }
    
    void add(string strStudent, int nGrade) {
        m_school[nGrade].push_back(strStudent);
        // Insersion sort would be better
        sort(m_school[nGrade].begin(), m_school[nGrade].end());
    }
    
    vector<string> grade(int nGrade) {
        return m_school[nGrade];
    }
};