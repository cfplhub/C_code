#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("*****  1、 开始游戏  *****\n");
	printf("*****  0、   离开    *****\n");
	printf("**************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	InintBoard(mine, ROWS, COLS,'0');
	InintBoard(show, ROWS, COLS,'*');

	Setmine(mine, ROW, COL);
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);

	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input;

	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				break;

		}


	} while (input);



	return 0;
}