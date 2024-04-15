#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void InintBoard(char board[ROW][COL], int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			
			if (j < col - 1)
				printf("|");

		}
		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");

				if (j < col - 1)
					printf("|");
				
			}
			printf("\n");
		}


	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	printf("玩家请下棋:>");
	int x, y;
	

	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <=row && y >= 1 && y <=col)
		{
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '*';
					break;
				}

				else
				{
					printf("棋位已被占用，请选择其他位置！\n");
					
				}

		}
		
		else
		{	
			printf("输入非法，请重新输入！\n");
			
			system("pause");
			system("cls");

			DisplayBoard(board, ROW, COL);
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");

	int x, y;

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}

	if (IsFull(board, row, col))
	{
		return 'Q';
	}

	return 'C';
}