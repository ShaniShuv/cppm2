#pragma once
#include <string>
#include "Direction.hpp"
#include <vector>
using std::vector;
using namespace std;
using ariel::Direction;

namespace ariel{
    class Board;
}


class ariel::Board {
    private:
        vector<vector<string>> board;
        int getRow();
        int getCol();

    public:
        // constructor
        Board();

        // post massage (given text, direction and location)
        void post(u_int row, u_int column, Direction dir, string txt);

        // read massage (given length, direction and location)
        string read(u_int row, u_int column, Direction dir, u_int len);

        void show();
};
