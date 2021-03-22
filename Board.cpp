#include "Board.hpp"
#include "Direction.hpp"
#include <map>
using ariel::Direction;
using namespace std;


namespace ariel 
{

    Board::Board()
    {
        u_int sri = 0; // start row index
        u_int sci = 0; // start col
        u_int eri = 0; // end row index
        u_int eci = 0; // end col
        map< map<u_int, u_int>, char> bm; // board map
    }

    void Board::post(u_int row, u_int col, Direction dir, string s){
        u_int temp = this->sri;
        if(row > temp ){
            this->sri = row;
        }
        temp = this->sci;
        if(col > temp ){
            this->sci = col;
        }
        for (size_t i = 0; i < s.length(); i++)
        {
            this->bm.insert<< row, col>, s.at(i)>;
        }
    }

    string Board::read(u_int row, u_int col, Direction dir, u_int len){
        string s = "";
        for (size_t i = 0; i < len; i++)
        {
            s += bm.get(row).get(col);
        }
        
        return s;
    }

    // TODO make const
    void Board::show(){
        u_int row = sri;
        u_int len = erc - src + 3;
        for (size_t i = 0; i < eri-sri; i++)
        {
            string temp = read(row, sci - 1, Direction::Horizontal, len);
        }        
    }
    
}