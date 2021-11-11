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
            //ʮ��֮һ���ʳ�4
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
    //��¼����
    RecordBoard();
    //�ƶ�����
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

    //���
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
    }

    //�ƶ�
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
    //�ƶ�
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

    //���
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
    }

    //�ƶ�
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
    //�ƶ�
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
    //���
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j+1]) {
                board[i][j] *= 2;
                board[i][j+1] = 0;
            }
        }
    }
    //�ƶ�
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
    //�ƶ�����
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

    //���
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == board[i][j-1]) {
                board[i][j] *= 2;
                board[i][j-1] = 0;
            }
        }
    }

    //�ƶ�
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
* Judge()�жϵ�ǰ��Ϸ״̬
* ����0����Ϸ���Լ���
* ����1����Ϸ��ʤ
* ����2����Ϸ�޷�������ʧ��
*/
int GAME2048::Judge() {
    //��Ӯ
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] >= WIN_SCORE) {
            return 1;       //Win
        }
    }
    //�п�
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] == 0) {
            return 0;
        }
    }

    //��������ͬ
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