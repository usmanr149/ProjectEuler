#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 9
#define COLS 9

int count = 0;

int printgrid(int puzzle[ROWS][COLS]){

  int i,j;

     printf("\n");
   for(i = 0 ; i < ROWS ; i++){
     for(j = 0 ; j < COLS ; j++){
       printf("%d   ", puzzle[i][j]);
     }
     printf("\n");
   }
   
}

int CheckRows(int puzzle [ROWS][COLS], int k, int l, int num){

  int i;
    for(i = 0 ; i < ROWS ; i++){
	if( puzzle[i][l] == num ) return 1;
    }
    return 0;
}

int CheckCols(int puzzle[ROWS][COLS], int k, int l, int num){

 int j;
    for(j = 0 ; j < COLS ; j++){
	if( puzzle[k][j] == num ) return 1;
    }
    return 0;
}

int CheckGrid(int puzzle[ROWS][COLS], int k, int l, int num){

  int i,j;
  int m = k/3;
  int n = l/3;

 for(i = 3*m ; i < 3*m+3 ; i++){
   for(j = 3*n ; j < 3*n+3 ; j++){
       if(puzzle[i][j] == num) return 1;
   }
}
 return 0;
}

int isSafe(int grid[ROWS][COLS], int row, int col, int num)
{

if( !CheckRows(grid, row, col, num) && !CheckCols(grid, row, col, num) && !CheckGrid(grid, row, col, num) ) return 1;
 else return 0;
}

int SolveSudoku(int grid[ROWS][COLS])
{
  int row, col;
  int num;

for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
	  if (grid[row][col] == 0){
count++;
            for( num = 1; num <= 9; num++ )
             {
         if(isSafe(grid, row, col, num) == 1 ) //Check if the number is safe to be assigned.
	{
           grid[row][col] = num; //If it is then make a tentative assigned.
           if (SolveSudoku(grid))  return 1;
	   grid[row][col] = 0;
         }
} //This is the end of for loop.
 return 0;  //This triggers backtracking, goes back to the for loop for the last function on the stack.
}
}

int main()
{

  int j,row=0,col=0;
  char line[132];
  FILE *fp;
  // 0 means unassigned cells
  char code[ROWS][COLS];
  int grid[ROWS][COLS];

  if((fp=fopen("sudoku.txt","r"))==NULL)
    {
      printf("Cannot open sudoku.txt.\n");
      return 0;
    }

  printf("Parameters read from sudoku.txt\n");

  char ch;// = getc(fp);

  int c, nl, frish = 0, i, sum = 0;

  nl = 0;
  while ((j = fgetc(fp)) != EOF){
    if (j == '\n' ) {
      nl++; //line number
      col = -1;
    }
    if(nl%10 != 0 && j != '\n'){ //If we are at line 9
      col++;
      row = (nl%10)-1;
      code[row][col] = j;
      grid[row][col] = code[row][col] - '0';
      if(row == 8 && col == 8){
	if (SolveSudoku(grid) == 1){
	  for(i=0;i<=2;i++)
	    sum += grid[0][i]*pow(10,2-i);
	  printf("sum = %d\n", sum);
	}
	else
	  printf("No solution exists\n");
      } 
    }
  }
  //fclose("sudoku.txt");
  
  printf("nl = %d\n", nl);
  printf("sum = %d\n", sum);
  getchar();
  
  printf("Done\n\n");
  
  return 0;
}
