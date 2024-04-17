#pragma once
#include<stdio.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<time.h>
#define EAST_COUNT 10

void  InintBoard(char board[ROWS][COLS], int row, int col, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void Setmine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);