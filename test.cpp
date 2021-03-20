#include "doctest.h"
#include "board.hpp"
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

TEST_CASE("read right horizontal"){
    // 20 so the board won't be too big and it would take more time to read
    size_t randRowToReadFrom = rand() % 20;
    size_t colReadingStart = rand() % 15;
    size_t rowLengthToRead = rand() % 15;

    std::array<char, rowLengthToRead> answerShouldBe;
    for (size_t i = 0; i < rowLengthToRead; i++)
    {
        answerShouldBe.at(i) = '_';
    }
    

    for (size_t i = 0; i < rowLengthToRead; i++)
    {
        string s1;
        cout << "please write a string";
        cin >> s1;
        int row = getrandom( rand()%20, rand()%20);
        int col =  getrandom( rand()%20, rand()%20);
        int d = (rand() % 10) % 2;
        b.post(row, col, d, s1);
        if(d == 0 && randRowToReadFrom == row){
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
            }
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
TEST_CASE("Don't initialize unnecessary"){
}

