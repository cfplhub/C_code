#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void  InintBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			 board[i][j] = set; 
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;

	printf("--------------------------扫雷游戏--------------------------\n");
	for (j = 0; j <= col; j++)
	{
		if (j == 0)
		{
			printf("  %d   ",j);
		}
		else
			printf("  %d   ", j);
	}
	printf("\n-----------------------------------------------------------\n");

	for (i = 1; i <= row; i++)
	{
		printf("  %d  |", i);
		for (j = 1; j <= col; j++)
		{
			printf("  %c  |", board[i][j]);
		}
		printf("\n-----------------------------------------------------------\n");
	}
	//printf("--------------------------扫雷游戏--------------------------\n");
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EAST_COUNT;
	int i, j;
	while (count)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;

		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}

}

int Get_Mine_Count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0');
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	if (Get_Mine_Count(mine, x, y) == 0)
	{
		show[x][y] = ' ';

		int i=0, j=0;

		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*' && i > 0 && i <= row && j > 0 && j <= col)
				{
					expand(mine, show, row, col, i, j);
				}
			}
		}
	}

	else
	{
		show[x][y] = Get_Mine_Count(mine, x, y) + '0';
	}
}


void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
	int x, y;

	int win = 0;
	
	while (win<row*col-EAST_COUNT)
	{

		printf("请输入您要排查的坐标：>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已被排查，请重新输入！\n");
			}

			else
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，您被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					system("pause");
					system("cls");
					break;
				}
				else
				{
					win++;
					expand(mine, show, ROW, COL, x, y);
					DisplayBoard(show, ROW, COL);
				}


			}

		}

		else
		{
			printf("输入的坐标非法，请重新输入\n");
		}

		if (win == row * col - EAST_COUNT)
		{
			printf("恭喜你，排雷成功！\n");
			DisplayBoard(show, ROW, COL);
			system("pause");
			system("cls");
		}
	}

}