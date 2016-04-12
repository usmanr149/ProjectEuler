#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 20

int main(){
  
  FILE *ptr_file;
  int i=0,j,**grid,size,g;
  
  ptr_file = fopen("numbers.dat", "r");
  if(!ptr_file){
    printf("Cannot open file\n");
    return 1;
  }
  
  grid=(int**)malloc(100*sizeof(int));
  for(i=0; i < ROWS; i++)
     grid[i] = malloc(100*sizeof(int));
   
   for(i=0; i < ROWS; i++){
    for(j=0; j < COLS; j++){
      if(!fscanf(ptr_file, "%d", &grid[i][j])) break;
      //printf("grid[%d][%d] = %d\n", i, j, grid[i][j]);
    }

    //printf("\n");
  }
  
  fclose(ptr_file);  
  long int multiple = 0, hold = -1;
  int w=0,b=0,c=0,d=0;
  int k;
  
  //Check Columns
  for(k=0;k<ROWS;k++){
    for(i=0;i<ROWS;i++){
      multiple = 1;
      for(j=k;j<k+4 && j<17;j++){
	multiple *= grid[i][j];
      }
      if(multiple > hold){
	hold = multiple;
	w = grid[i][k];
	b = grid[i][k+1];
	c = grid[i][k+2];
	d = grid[i][k+3];
      }
    }
  }

  //Check Rows
  for(k=0;k<ROWS;k++){
    for(i=0;i<ROWS;i++){
      multiple = 1;
      for(j=k;j<k+4 && j<17;j++){
	multiple *= grid[j][i];
      }
      if(multiple > hold){
	hold = multiple;
	w = grid[k][i];
	b = grid[k+1][i];
	c = grid[k+2][i];
	d = grid[k+3][i];
      }
    }
  }
   
  int a;
  //Check Diagonal downward and right
  for(k=0;k<17;k++){ //From 0 to 16
    for(i=0;i<17;i++){ //From 0 to 16
      a=i;
      multiple = 1;
      for(j=k;j<k+4;j++){ //From 0 to 19
	multiple *= grid[j][a];
	//printf("grid[%d][[%d] = %d\n", j,a, grid[j][a]);
	a++;
      }
      if(multiple > hold){
	hold = multiple;
	w = grid[k][i];
	b = grid[k+1][i+1];
	c = grid[k+2][i+2];
	d = grid[k+3][i+3];
      }
    }
  }

  //Check Diagonal upwward and left
  for(k=ROWS-1;k>2;k--){ //From 19 to 3.
    for(i=0;i<ROWS;i++){ //From 0 to 19.
      a=i;
      multiple = 1;
      for(j=k;j>k-4;j--){ //least from 3 and 0.
	multiple *= grid[j][a];
	a++;
      }
      if(multiple > hold){
	hold = multiple;
	w = grid[k][i];
	b = grid[k-1][i+1];
	c = grid[k-2][i+2];
	d = grid[k-3][i+3];
      }
    }
  }

  printf("maximum value = %ld\n", hold);
  printf("w*b*c*d = %d\n", w*b*c*d);
  printf("w = %d\n", w);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %d\n", d);

  free(grid);
  
}
