#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void Menu()
{
	printf("*****************************\n");
	printf("******1��play   0��exit******\n");
	printf("*****************************\n");

}

void game()
{
	char board[ROW][COL] = { 0 };
	InintBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);

	char ret =0 ;

	while (1)
	{
		playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}

		computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
		system("pause");
		system("cls");
	}

	else if (ret == '#')
	{
		printf("����Ӯ��\n");
		system("pause");
		system("cls");
	}
	else
		printf("ƽ�֣�\n");
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		Menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����\n");
			system("pause");
			system("cls");
			break;
		}


	} while (input);




	return 0;
}