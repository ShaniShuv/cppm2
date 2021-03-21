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
    size_t rowS = rand() % 20;
    size_t colS = rand() % 15;
    size_t lengthS = rand() % 15;

    std::array<char, lengthS> s;
    for (size_t i = 0; i < lengthS; i++)
    {
        s.at(i) = '_';
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
        if(d == 0 && rowS == rowT){
            if(colT <= colS && colS <= colT + t.length()){
                size_t copy_length;

                // if the temp ends before the original string
                if (colS + s.length() >= colT + t.length())
                {
                    copy_length = colT + t.length() - colS;
                }
                
                // if the original string end before the 
                else{
                    copy_length = s.length();
                }

                
                for (size_t i = 0; i < copyLength; i++)
                {
                    s.at(i) = t.at(i - colT + colS);
                }
            }

            // if the temp start after the original string we would like to check
            if(colS + s.length() >= colT && colT >= colS){

                


                size_t copy_length;
                

                // if the temp string ends before the original string
                if(t.length() + colT <= s.length() + colS){
                    copy_length = t.length();
                }
                else{
                    copy_length = colT - colS + s.length();
                }



                // if the temp ends after the og string
                for (size_t i = 0; i < copy_length; i++)
                {
                    s.at(i - colS + colT) = t.at(i);
                }
            }
        }
        else if(d == 1 &&  rowT <= rowS &&  rowS <= rowT + t.length() 
                            && colS +  lengthS >= colT && colT >= colS){
                                    s.at(col - colS) = t.at(row - randRowToReadFrom);
        }

    }

    string s2 = b.read(rowS, colS, 0, lengthS)
    for (size_t i = 0; i < lengthS; i++)
    {
        CHECK_EQ(s.at(i), s2.at(i));
    }  
}

// for right col reading
TEST_CASE("Right col reading"){
    // 20 so the board won't be too big and it would take more time to read
    size_t ansStartCol = rand() % 20;
    size_t ansStartRow = rand() % 15;
    size_t rowLengthToRead = rand() % 15;

    std::array<char, rowLengthToRead> answerShouldBe;
    for (size_t i = 0; i < rowLengthToRead; i++)
    {
        answerShouldBe.at(i) = '_';
    }
    

    for (size_t i = 0; i < rowLengthToRead; i++)
    { // to do abs value 
        string s1;
        cout << "please write a string";
        cin >> s1;
        int row = getrandom( rand()%20, rand()%20);
        int col =  getrandom( rand()%20, rand()%20);
        int d = (rand() % 10) % 2;
        b.post(row, col, d, s1);
        if(d == 0 && randRowToReadFrom == row){
            if()

            /*
            if(s1.length() + col >= colReadingStart && colReadingStart >= col){
                size_t copyLength = min{col + s1.length() - colReadingStart,  rowLengthToRead};
                for (size_t i = 0; i < copyLength; i++)
                {
                    answerShouldBe.at(i) = s1.at(i - col + colReadingStart);
                }
            }
            if(colReadingStart + rowLengthToRead >= col && col >= colReadingStart){
                size_t copyLength = min{s1.length(),  rowLengthToRead + colReadingStart - col};
                for (size_t i = 0; i < copyLength; i++)
                {
                    answerShouldBe.at(i - colReadingStart + col) = s1.at(i);
                }
            }*/
        }
        else if(d == 1 &&  row <= randRowToReadFrom &&  randRowToReadFrom <= row + s1.length() 
                            && colReadingStart +  rowLengthToRead >= col && col >= colReadingStart){
                                    answerShouldBe.at(col - colReadingStart) = s1.at(row - randRowToReadFrom);
        }

    }

    string s2 = b.read(randRowToReadFrom, colReadingStart, 0, rowLengthToRead)
    for (size_t i = 0; i < rowLengthToRead; i++)
    {
        CHECK_EQ(answerShouldBe.at(i), s2.at(i));
    }  
}


// for right show
TEST_CASE(""){
}

