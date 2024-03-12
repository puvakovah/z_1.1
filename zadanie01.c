#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9
#define OK 0
#define FAIL 1

void vypis_sudoku(int *sudoku)
{
     int s[SIZE][SIZE];
     
     srand(time(NULL));
     s[SIZE][SIZE]=*sudoku;

     for (int row = 1; row <= SIZE; row++) {
     for (int col = 1; col <= SIZE; col++) {
          s[row][col]=rand()%9+1;//zatial iba pomocne vygenerovanie cisel do sudoku
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

int pozicie(int *sudoku, int row, int col, int num)
{
     int s[SIZE][SIZE];

     s[SIZE][SIZE]=*sudoku;
     for(int i=0; i<SIZE; i++)//kontrola riadku a stlpca ci je tam este mozne vypisat cislo
     {
          if(s[row][i] == num || s[i][col] == num)
          return 0;
     } 
}

void main(void)
{
     int *sudoku;
     vypis_sudoku(sudoku);
}