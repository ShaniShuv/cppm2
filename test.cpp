#include "doctest.h"
#include "Board.hpp"
#include <stdexcept>
#include <cmath>
#include <array>
#include <iostream>
#include <string>
using namespace std;

// using namespace ariel;

int getrandom(int min, int max){
    // just to be sure
    if(min < 0){
        min *= -1;
    }
    if(max < 0){
        max *= -1;
    }
    if(min > max){
        int temp = min;
        min = max;
        max = temp;
    }

    int i = rand() % 10;
    i %= 5;
    int k = pow(10, i);
    int r = rand() % k;
    return r;
}


TEST_CASE("Don't initialize unnecessary"){
    board b;

    // for negative value
    int row = getrandom( rand(), rand());
    int col =  getrandom( rand(), rand());
    int d = (rand() % 10) % 2;
    string s1;
    cout << "please write a string";
    cin >> s1;
    CHECK_THROWS_MESSAGE(b.post(-row, col, d, s1) == "negative row");
    CHECK_THROWS_MESSAGE(b.post(row, -col, d, s1) == "negative col");

    // for wrong diraction
    CHECK_THROWS_MESSAGE(b.post(row, col, -d, s1) == "negative diraction");
    d += rand();
    CHECK_THROWS_MESSAGE(b.post(row, col, d, s1) == "not a valid diraction");
}

TEST_CASE("read right specfic"){
    board b;
    b.post(0, 0, 0 "abc");
    string sRead = b.read(0, 0, 0, 4);
    string sComp = "abc_"
    for (size_t i = 0; i < 5; i++)
    {
        CHECK_EQ(sRead.at(i), sComp.at(i));
    }
    b.post(0, 5, "fghi ");
    sRead = b.read(0, 0, 0, 10);
    string sComp = "abc__fghi ";
    for (size_t i = 0; i < 10; i++)
    {
        CHECK_EQ(sRead.at(i), sComp.at(i));
    }

    b.post(2, 1, 1, "shani");
    sRead = b.read(0, 1, 1, 8);
    string sComp = "c_shani_";
    for (size_t i = 0; i < 8; i++)
    {
        CHECK_EQ(sRead.at(i), sComp.at(i));
    }

    // to check drissa
     b.post(4, 0, 0, "  u");
     b.post(5, 1, 0, "+v");
    sRead = b.read(2, 2, 1, 4);
    string sComp = "shuv";
    for (size_t i = 0; i < 4; i++)
    {
        CHECK_EQ(sRead.at(i), sComp.at(i));
    }

}

TEST_CASE("read right random horizontal"){
        // 20 so the board won't be too big and it would take more time to read
        size_t rowSR = rand() % 20;
        size_t colSR = rand() % 15;

        size_t rowSC = rand() % 20;
        size_t colSC = rand() % 15;
        size_t lengthS = rand() % 15;

        std::array<char, lengthSR> sr;
        std::array<char, lengthSR> sc;
        for (size_t i = 0; i < lengthSR; i++)
        {
            sr.at(i) = '_';
            sc.at(i) = '_';
        }


        for (size_t i = 0; i < lengthS; i++)
        {
            string t;
            cout << "please write a string";
            cin >> t;
            int rowT = getrandom( rand()%20, rand()%20);
            int colT =  getrandom( rand()%20, rand()%20);
            int d = (rand() % 10) % 2;
            b.post(rowT, colT, d, t);

            // init the row string
            if(d == 0 && rowSR == rowT)
            {

                //checks if start before our row string and there's hafifa beneihen
                if(colT <= colSR && colSR <= colT + t.length())
                {
                    size_t copy_length;

                    // if the temp ends before the original string
                    if (colSR + sr.length() >= colT + t.length())
                    {
                        copy_length = colT + t.length() - colSR;
                    }

                    // if the original string end before the
                    else
                    {
                        copy_length = sr.length();
                    }


                    for (size_t i = 0; i < copyLength; i++)
                    {
                        sr.at(i) = t.at(i - colT + colSR);
                    }
                }
            

                // if the temp start after the row string we would like to check
                // and if there's hafifa
                if(colSR + sr.length() >= colT && colT >= colSR)
                {
                    size_t copy_length;


                    // if the temp string ends before the original string
                    if(t.length() + colT <= sr.length() + colSR){
                        copy_length = t.length();
                    }

                    else{
                        copy_length = colT - colSR + sr.length();
                    }

                    // if the temp ends after the og string
                    for (size_t i = 0; i < copy_length; i++)
                    {
                        sr.at(i - colSR + colT) = t.at(i);
                    }
            }
        }
        else if(d == 1 &&  rowT <= rowSR &&  rowSR <= rowT + t.length() && colSR +  lengthSR >= colT && colT >= colSR){
            sr.at(colT - colSR) = t.at(rowT - rowSR);
        }
        // end of init the row string

        // start of init the col string
        if(d == 1 && colSC == colT)
        {

                //checks if start before our row string and if there's hafifa beneihen
                if(rowT <= rowSC && rowSC <= rowT + t.length())
                {
                    size_t copy_length;

                    // if the temp ends before the original string
                    if (rowSC + sc.length() >= rowT + t.length())
                    {
                        copy_length = rowT + t.length() - rowSC;
                    }

                    // if the original string end before the
                    else
                    {
                        copy_length = sc.length();
                    }


                    for (size_t i = 0; i < copyLength; i++)
                    {
                        sc.at(i) = t.at(i - rowlT + rowSC);
                    }
                }

                // if the temp start after the row string we would like to check
                // and if there's hafifa
                if(rowSC + sc.length() >= rowT && rowT >= rowSC)
                {
                    size_t copy_length;


                    // if the temp string ends before the original string
                    if(t.length() + rowT <= sc.length() + rowSC){
                        copy_length = t.length();
                    }

                    else{
                        copy_length = rowT - rowSC + sc.length();
                    }

                    // if the temp ends after the og string
                    for (size_t i = 0; i < copy_length; i++)
                    {
                        sc.at(i - rowSC + rowT) = t.at(i);
                    }
            }
        }
        else if(d == 0 &&  colT <= colSC && colSC <= colT + t.length() && rowSC + lengthS >= rowT && rowT >= rowSC){
            sc.at(rowT - rowSC) = t.at(colT - colSC);
        }
        // end of init the col string

    }

    string srComp = b.read(rowSR, colSR, HORI, lengthS)
    string scComp = b.read(rowSC, colSC, VER, lengthS)
    for (size_t i = 0; i < lengthS; i++)
    {
        CHECK_EQ(sr.at(i), srComp.at(i));
        CHECK_EQ(sc.at(i), scComp.at(i));
    }
}


// for right show
TEST_CASE(""){
}

