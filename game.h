#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3//��
#define COL 3//��

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW] [COL],int row, int col);


//���Ӯ - '*'
//����Ӯ - '#'
//ƽ�� - 'Q'
//���� - 'C'
char Iswin(char board[ROW][COL],int row,int col);
