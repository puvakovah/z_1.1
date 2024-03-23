#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9
#define OK 0
#define FAIL 1

void vypis_sudoku(int *sudoku)
{
     int s[SIZE][SIZE];
     
     for(int row=1;row<=SIZE;row++)
     {
          for(int col=1;col<=SIZE;col++)
          {
               sudoku=&s[row][col];
          }
     }

     for (int row = 1; row <= SIZE; row++) {
     for (int col = 1; col <= SIZE; col++) {
          if(col%3==0)
          {
               printf("%d ", s[row][col]);
               printf("\t");
          }
          else
          {
               printf("%d ", s[row][col]);
          }
        }
     if(row%3==0)
          printf("\n\n");
     else
          printf("\n");
    } 
}

int pozicie(int *sudoku, int row, int col, int num)//funkcia na kontrolu, ci moze byt cislo vlozene na danu poziciu
{
     int s[SIZE][SIZE];

     s[SIZE][SIZE]=*sudoku;
     for(int i=0; i<SIZE; i++)//kontrola riadku a stlpca
     {
          if(s[row][i] == num || s[i][col] == num)
          return 0;
     } 
     for(int i=0; i<3; i++)//schema 3x3
     {
          for(int j=0; j<3; j++)
          {
               if(s[i][j] == num)
               return 0;
          }
     }
}

void generuj_sudoku(int *sudoku, int row, int col)
{
     int s[SIZE][SIZE];
     srand(time(NULL));

     s[SIZE][SIZE]=*sudoku;
     for(int num=1; num<=SIZE; num++)
     {
          if(pozicie(sudoku,row,col,num))
          {
              s[row][col]=num;
          }     
     }
    
}
void main(void)
{
     int *sudoku;
     for(int row=1;row<=SIZE;row++)
     {
          for(int col=1;col<=SIZE;col++)
          {
               generuj_sudoku(sudoku,row,col);
          }
     } 
     vypis_sudoku(sudoku); 
}