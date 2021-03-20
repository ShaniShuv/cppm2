#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

namespace ariel{
    void post(int row, int col, Direction d, std::string s);
    std::string read(int row, int col, Direction d, size_t length);
    void show();
};