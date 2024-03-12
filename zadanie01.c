#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9
#define OK 0
#define FAIL 1

void vypis_sudoku(int a[SIZE][SIZE])
{

        for (int row = 1; row <= SIZE; row++) {
        for (int col = 1; col <= SIZE; col++) {
          if(col%3==1)
          {
               printf("\t%d ", a[row][col]);
          }
          else
          {
               printf("1 ", a[row][col]);
          }

        }
        printf("\n");
    } 
}


void main(void)
{
     int sudoku[SIZE][SIZE];
     vypis_sudoku(sudoku);
}