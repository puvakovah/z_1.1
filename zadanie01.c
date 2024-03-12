#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define SIZE 9

void vypis_sudoku(int a[SIZE][SIZE])
{

        for (int row = 1; row <= SIZE; row++) {
        for (int col = 1; col <= SIZE; col++) {
            printf("%d ", a[row][col]);
        }
        printf("\n");
    } 
}