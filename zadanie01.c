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
               printf("%d ", *sudoku+row*SIZE+col);
               printf("\t");
          }
          else
          {
               printf("%d ", *sudoku+row*SIZE+col);
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
          if(*sudoku+i*SIZE+col == num || *sudoku+i*SIZE+row== num)
          return 0;
     } 
     for(int i=0; i<3; i++)//schema 3x3
     {
          for(int j=0; j<3; j++)
          {
               if(*sudoku+i*SIZE+j == num)
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
              *sudoku=num;
          }     
     }   
}

void nahodne_sudoku(void) {
    int *s;
    for(int row=0;row<SIZE;row++)
    {
     for(int col=0;col<SIZE;col++)
     {
          generuj_sudoku(s,row,col);   
     }
    }

    vypis_sudoku(s);
}

int main()
{
     nahodne_sudoku();
     return 0;
}