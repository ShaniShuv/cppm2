#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <map>
using ariel::Direction;
using namespace std;

const Direction HORI = Direction::Horizontal;
const Direction VER = Direction::Vertical;

namespace ariel 
{

    

    void Board::post(u_int row, u_int col, Direction dir, string s)
    {
        if(s.length() == 0) 
        {
            return;
        }
        u_int temp = (u_int)min((size_t)row, (size_t)row + s.length());
        if(row > temp )
        {
            this->sri = row;
        }
        if(col > this->sci)
        {
            this->sci = col;
        }

        temp = (u_int)min((size_t)row, (size_t)row + s.length());
        if(dir == HORI)
        { 
            if(row + s.length() > row && row + s.length() > this->eri)
            {
                this->eri = row + s.length();
            }
            else if(row + s.length() < row && temp < this->sri)
            {   
                this->sri = temp;
            }
            for (size_t i = 0; i < s.length(); i++)
            {
                bm[make_pair(row, col)] = s.at(i);
                col++;
            }

        }

        else
        { 
            temp = (u_int)min((size_t)col, (size_t)col + s.length());
            if(col + s.length() > col && col + s.length() > this->eci)
            {
                this->eci = col + s.length();
            }
            else if(col + s.length() < col && temp < this->sci)
            {   
                this->sci = temp;
            }
            for (size_t i = 0; i < s.length(); i++)
            {
                bm[make_pair(row, col)] = s.at(i);
                row++;
            }

        }
        
    }

    string Board::read(u_int row, u_int col, Direction dir, u_int len){
        if(bm.empty()){
            return "the board is empty";
        }
        string st;
        if(dir == HORI){
            for (size_t i = 0; i < len; i++)
            {
                char c = bm[make_pair(row, col)];
                if(c==0) 
                {
                    c = '_';
                }
                st += c;
                col++;
            }
        }
        else
        {
            for (size_t i = 0; i < len; i++)
            {
                char c = bm[make_pair(row, col)];
                if(c==0)
                {
                    c = '_';
                }
                st += c;
                row++;
            }
            
        }
        return st;
    }

    // TODO make const
    void Board::show(){
        if(bm.empty()){
            cout << "the board is empty"<<endl;
        }
        u_int row = sri;
        u_int len = eri - sri + 3;
        for (size_t i = 0; i < eri-sri; i++)
        {
            string temp = read(row, sci - 1, HORI, len);
        }        
    }
    
}