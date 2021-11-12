#include <stdio.h>
#include "game2048.h"
#include <conio.h>
#include <iostream>
using namespace std;


void showBoard(int* map);		//显示棋盘

int main(void) {
	srand((unsigned)time(NULL));	//用当前时间作为随机数种子
	GAME2048 game;		//创建游戏对象
	game.init();		//游戏初始化
	char control;		//用于读取WASD
	int* p;				//用来存棋盘指针
	p = game.getBoard();

	while (1) {
		system("cls");			//清屏
		showBoard(p);			//显示棋盘
		control = _getch();		//获取操作

		switch (control) {
		case 'H':				//上
			game.moveUp();
			//printf("Up!\n");
			break;
		case 'P':				//下
			game.moveDown();
			//printf("Down!\n");
			break;
		case 'M':				//左
			game.moveRight();
			//printf("Right!\n");
			break;
		case 'K':				//右
			game.moveLeft();
			//printf("Left!\n");
			break;
		default:
			continue;
		}
		
		if (game.comparePre() == 0) {	//移动有效则开始下一回合
			game.addRandom();
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
	//显示游戏进度
	cout << "用上下左右键来操控,当有一个数字等于64时，游戏成功" << endl;
	cout << "     ------------------------------" << endl;
	cout << "     丨     丨     丨     丨     丨" << endl;
	printf("     丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[0], map[1], map[2], map[3]);
	cout << "     丨     丨     丨     丨     丨" << endl;
	cout << "     ------------------------------" << endl;
	cout << "     丨     丨     丨     丨     丨" << endl;
	printf("     丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[4], map[5], map[6], map[7]);
	cout << "     丨     丨     丨     丨     丨" << endl;
	cout << "     ------------------------------" << endl;
	cout << "     丨     丨     丨     丨     丨" << endl;
	printf("     丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[8], map[9], map[10], map[11]);
	cout << "     丨     丨     丨     丨     丨" << endl;
	cout << "     ------------------------------" << endl;
	cout << "     丨     丨     丨     丨     丨" << endl;
	printf("     丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[12], map[13], map[14], map[15]);
	cout << "     丨     丨     丨     丨     丨" << endl;
	cout << "     ------------------------------" << endl;
}