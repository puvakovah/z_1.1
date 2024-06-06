#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 9
#define OK 0
#define FAIL 1
#define N 100

void vypis_sudoku(int *sudoku)
{
     for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", *(sudoku + row * SIZE + col));
            if ((col + 1) % 3 == 0 && col < SIZE - 1)
                printf("| ");
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row < SIZE - 1)
            printf("------+-------+------\n");
    }
    printf("\n");
}

int pozicie(int *sudoku, int row, int col, int num)//funkcia na kontrolu, ci moze byt cislo vlozene na danu poziciu
{
     for(int i = 0; i < SIZE; i++)//kontrola riadku 
     {
          if(*(sudoku + i * SIZE + col) == num )
          return 1;
     } 

     for(int i = 0; i < SIZE; i++)//kontrola stlpca
     {
          if(*(sudoku + row * SIZE + i) == num)
          return 1;
     } 

     for(int i = 0; i < 3; i++)//schema 3x3
     {
          for(int j = 0; j < 3; j++)
          {
               if(*(sudoku+((row-row%3)+i)*SIZE+((col-col%3)+j)) == num)
               return 1;
          }
     }
     return 0;
}

void generuj_sudoku(int *sudoku)
{
     int num; 
     
     srand(time(NULL));
     for (int i = 0; i < SIZE * SIZE; i++) 
     {
        sudoku[i] = 0;
     }

     for(int row = 0; row < SIZE; row++)
     {
          for(int col = 0; col < SIZE; col++)
          {
               int pokus = 0;
               do
               {
                    num = rand()% SIZE + 1;
                    pokus++;
                    if(pokus > SIZE * SIZE)
                         break;
               } while(pozicie(sudoku,row,col,num));
               
               *(sudoku+row*SIZE+col)=num;
          }
     }
    

     
}

void nahodne_sudoku(void) 
{   
     int *sudoku=(int*)malloc(SIZE*SIZE*sizeof(int));
     
     generuj_sudoku(sudoku);   

     vypis_sudoku(sudoku);
}

int main()
{
     nahodne_sudoku();
     return 0;
}