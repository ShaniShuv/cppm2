#pragma once
#include <string>
#include "Direction.hpp"
#include <vector>
#include <cmath>
#include <map>
using std::vector;
using namespace std;
using ariel::Direction;


const u_int UINT_MAX = (u_int)pow(2, 32);

namespace ariel{
    class Board;
}


class ariel::Board {
    private:
    
        u_int sri; // start row index
        u_int sci; // start col
        u_int eri; // end row index
        u_int eci; // end col
        map<pair<u_int, u_int>, char> bm; // board map
    

    public:
        // constructor
        Board()
        {
            sri = UINT_MAX-1; // start row index
            sci = UINT_MAX-1; // start col
            eri = 0; // end row index
            eci = 0; // end col
            map<pair<u_int, u_int>, char> bm; // board map
        }

        // post massage (given text, direction and location)
        void post(u_int row, u_int col, Direction dir, string s);

        // read massage (given length, direction and location)
        string read(u_int row, u_int col, Direction dir, u_int len);

        void show();
};
