#pragma once

#include <vector>
#include <sstream>
#include <cmath>

namespace queen_attack {
    class chess_board;
}

//queen_attack.cpp
//#include "queen_attack.h"

using namespace std;

class queen_attack::chess_board {
/* Class that tracks and determines if two queens can attack eachother */

private:
    typedef pair<int, int> square;
    square m_pnWhite;
    square m_pnBlack;
public:
    // Defaults
    chess_board() : m_pnWhite({0,3}), m_pnBlack({7,3}) { }
    
    chess_board(square pnWhite, square pnBlack) :
    m_pnWhite(pnWhite), m_pnBlack(pnBlack) {
        if (m_pnBlack == m_pnWhite)
            throw domain_error("Queens cannot be in the same position");
    }
    
    square black() const { return m_pnBlack; }
    square white() const { return m_pnWhite; }
    
    bool can_attack() const {
        /* True if the queens can attack each other */
        if(m_pnWhite.first  == m_pnBlack.first ||
           m_pnWhite.second == m_pnBlack.second )
            // Straight
            return true;
        if (abs(m_pnWhite.first  - m_pnBlack.first ) ==
            abs(m_pnWhite.second - m_pnBlack.second))
            // Diagonal
            return true;
        // Default
        return false;
    }
    
    operator string() const {
        /* Prints the board */
        stringstream strBoard;
        for (int i = 0; i <= 7; i++) {
            for (int j = 0; j <= 7; j++) {
                square squPos = make_pair(i, j);
                if(squPos == m_pnWhite)
                    strBoard << 'W';
                else if(squPos == m_pnBlack)
                    strBoard << 'B';
                else
                    strBoard << '_';
                if (j < 7)
                    strBoard << ' ';
            }
            strBoard << endl;
        }
        return strBoard.str();
    }
};