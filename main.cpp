#include <stdio.h>
#include "game2048.h"
#include <conio.h>
#include <iostream>
using namespace std;


void showBoard(int* map);		//��ʾ����

int main(void) {
	srand((unsigned)time(NULL));	//�õ�ǰʱ����Ϊ���������
	GAME2048 game;		//������Ϸ����
	game.init();		//��Ϸ��ʼ��
	char control;		//���ڶ�ȡWASD
	int* p;				//����������ָ��
	p = game.getBoard();

	while (1) {
		system("cls");			//����
		showBoard(p);			//��ʾ����
		control = _getch();		//��ȡ����

		switch (control) {
		case 'H':				//��
			game.moveUp();
			if (game.comparePre() == 0) {	//�ƶ���Ч��ʼ��һ�غ�
				game.addRandom();
			}
			//printf("Up!\n");
			break;
		case 'P':				//��
			game.moveDown();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Down!\n");
			break;
		case 'M':				//��
			game.moveRight();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Right!\n");
			break;
		case 'K':				//��
			game.moveLeft();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Left!\n");
			break;
		default:
			continue;
		}
		


		if (game.Judge() == 1) {
			printf("you win!\n");
			system("pause");
			return 1;
		}
		else if (game.Judge() == 2) {
			printf("you lose!\n");
			system("pause");
			return 2;
		}

	}

	return 3;
}

void showBoard(int* map) {
	//��ʾ��Ϸ����
	int i = 0;

	cout << "��WASD���ٿ�,����һ�����ֵ���64ʱ����Ϸ�ɹ�" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[0], map[1], map[2], map[3]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[4], map[5], map[6], map[7]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[8], map[9], map[10], map[11]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[12], map[13], map[14], map[15]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
}