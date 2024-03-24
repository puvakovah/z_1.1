#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9
#define OK 0
#define FAIL 1

void vypis_sudoku(int *sudoku)
{
     for (int row = 1; row <= SIZE; row++) {
     for (int col = 1; col <= SIZE; col++) {
          if(col%3==0)
          {
               printf("%d ", *sudoku);
               printf("\t");
          }
          else
          {
               printf("%d ", *sudoku);
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
     for(int i=0; i<SIZE; i++)//kontrola riadku a stlpca
     {
          if(*sudoku+row == num || *sudoku+col == num)
          return 0;
     } 
     for(int i=0; i<3; i++)//schema 3x3
     {
          for(int j=0; j<3; j++)
          {
               if(*sudoku == num)
               return 0;
          }
     }
}

void generuj_sudoku(int *sudoku, int row, int col)
{
     srand(time(NULL));

     for(int num=1; num<=SIZE; num++)
     {
          if(pozicie(sudoku,row,col,num))
          {
              sudoku=num;
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