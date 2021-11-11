#pragma once
#ifndef GAME2048_H
#define GAME2048_H

#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 4
#define WIN_SCORE 2048

class GAME2048 {
private:
    int board[4][4];
    int previous[4][4];


public:
    GAME2048() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this->board[i / 4][i % 4] = 0;
            this->previous[i / 4][i % 4] = 0;
        }
    }
    void init() {
        addRandom();
        addRandom();
    };
    void addRandom();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int  Judge();
    //判断移动后是否相同，没变化则返回1
    int  comparePre() { 
        int x = 0;
        for (int i = 0; i < SIZE * SIZE; i++) {
            if (this->board[i / 4][i % 4] == this->previous[i / 4][i % 4])
                x++;
        }

        if (x >= 16) {
            return 1;
        }
        return 0;
    };
    //记录棋盘到previous
    void RecordBoard() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this->previous[i / 4][i % 4] = this->board[i / 4][i % 4];
        }
    };
    //获取棋盘指针
    int * getBoard() {
        return &this->board[0][0];
    };
};

#endif
