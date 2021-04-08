#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <map>
#include <cmath>
using ariel::Direction;
using namespace std;

// const u_int UINT_MAX = (u_int)pow(2, 32);
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
        if(row < sri)
        {
            sri = row;
        }
        if(col < sci)
        {
            sci = col;

            // mytest
            cout<< "srci"<< endl;
        }
        if(row > eri)
        {
            eri = row;
        }
        if(col > eci)
        {
            eci = col;
        }

        if(dir == HORI)
        { 
            
            if(col < col + s.length())
            {
                if(col + s.length() > eci)
                {
                    eci = col + s.length();
                }
                
            }
            else
            {
                sci = 0;
                eci = UINT_MAX;
            }
            

            for (size_t i = 0; i < s.length(); i++)
            {
                bm[make_pair(row, col)] = s.at(i);
                col++;
            }

        }

        else
        { 
            if(row < row + s.length())
            {
                if(row + s.length() > eri)
                {
                    eri = row + s.length();
                }
                
            }
            else
            {
                sri = 0;
                eri = UINT_MAX;
            }
            for (size_t i = 0; i < s.length(); i++)
            {
                bm[make_pair(row, col)] = s.at(i);
                row++;
            }

        }
        
    }

    string Board::read(u_int row, u_int col, Direction dir, u_int len){
//         if(bm.empty()){
//             return "the board is empty";
//         }

        string st;
        // st += row;
        // st += ": ";
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

//my test
        // cout<< "sri"<< endl;
        // cout<< sri << endl;
        // cout<< "eri"<< endl;
        // cout<<eri << endl;
        // cout<< "sci"  << endl;
        // cout<< sci << endl;
        // cout<< "eci" << endl;
        // cout<< eci << endl;
        // cout << '\n' <<endl;

        return st;
    }

    // TODO make const
    void Board::show(){
        if(bm.empty()){
            cout << "the board is empty"<<endl;
        }
        u_int row = sri - 1;
        u_int len = eri - sri + 3;

        for (size_t i = 0; i <= eri-sri; i++)
        {
            string temp;
            cout << (row + i);
            temp+= ": ";
            temp += read(row + i, sci - 1, HORI, len);
            cout << temp << endl;
        }        
    }
    
}
