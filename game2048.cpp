#include "game2048.h"
#include "stdio.h"


void GAME2048::addRandom() {
    int random;
    if (Judge() != 0) {
        return;
    }

    while (1) {
        random = rand() % 16;
        if (this->board[random / 4][random % 4] == 0) {
            //十分之一概率出4
            if (rand() % 10 == 0) {
                this->board[random / 4][random % 4] = 4;
            }
            else {
                this->board[random / 4][random % 4] = 2;
            }
            break;
        }
    }
}

void GAME2048::moveUp() {
    //记录棋盘
    RecordBoard();
    //移动两次
    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i + 1][j];
                    board[i + 1][j] = 0;
                }
            }
        }
    }

    //相加
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
    }

    //移动
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = 0;
            }
        }
    }


}
void GAME2048::moveDown() {
    RecordBoard();
    //移动
    for (int x = 0; x < 2; x++) {
        for (int i = SIZE - 1; i > 0; i--) {
            for (int j = SIZE - 1; j >= 0; j--) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = 0;
                }
            }
        }
    }

    //相加
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
    }

    //移动
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] == 0) {
                board[i][j] = board[i - 1][j];
                board[i - 1][j] = 0;
            }
        }
    }

}

void GAME2048::moveLeft() {
    RecordBoard();
    //移动
    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i][j+1];
                    board[i][j+1] = 0;
                }
            }
        }
    }
    //相加
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j+1]) {
                board[i][j] *= 2;
                board[i][j+1] = 0;
            }
        }
    }
    //移动
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                board[i][j] = board[i][j+1];
                board[i][j+1] = 0;
            }
        }
    }
}
void GAME2048::moveRight() {
    RecordBoard();
    //移动两次
    for (int x = 0; x < 2; x++) {
        for (int i = SIZE - 1; i >= 0; i--) {
            for (int j = SIZE - 1; j > 0; j--) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i][j-1];
                    board[i][j-1] = 0;
                }
            }
        }
    }

    //相加
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == board[i][j-1]) {
                board[i][j] *= 2;
                board[i][j-1] = 0;
            }
        }
    }

    //移动
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == 0) {
                board[i][j] = board[i][j-1];
                board[i][j-1] = 0;
            }
        }
    }

}

/*
* Judge()判断当前游戏状态
* 返回0：游戏可以继续
* 返回1：游戏获胜
* 返回2：游戏无法继续，失败
*/
int GAME2048::Judge() {
    //判赢
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] >= WIN_SCORE) {
            return 1;       //Win
        }
    }
    //判空
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] == 0) {
            return 0;
        }
    }

    //判相邻相同
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3) {
                if (board[i][j] == board[i + 1][j]) {
                    return 0;
                }
            }
            if (j < 3) {
                if (board[i][j] == board[i][j + 1]) {
                    return 0;
                }
            }
        }
    }

    return 2;   //Defeatd
}