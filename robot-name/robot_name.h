#pragma once

#include <string>
#include <sstream>
#include <iomanip>

namespace robot_name {
    using namespace std;
    
    class robot;
}

class robot_name::robot {
private:
    static int m_nSerialNumber;
    string m_strName;
    
    string make_name(int nSerialNumber) {
        /* Makes an AB123 type name from an integer */
        // Probably a better way to do this
        stringstream strName;
        int remainer = nSerialNumber;
        {   //Adds the two letters
            strName << static_cast<char>(remainer % 26 + 65);
            remainer /= 26;
            strName << static_cast<char>(remainer % 26 + 65);
            remainer /= 26;
        }
        // Prints the last three digits of remainer
        strName << setfill('0') << setw(3) << (remainer % 1000);
        return strName.str();
    }
    
public:
    robot() { reset(); }
    
    string name() const { return m_strName; }
    
    void reset() {
        m_strName = make_name(m_nSerialNumber++);
    }
};

//Typicaly in the .cpp file
int robot_name::robot::m_nSerialNumber = 0;