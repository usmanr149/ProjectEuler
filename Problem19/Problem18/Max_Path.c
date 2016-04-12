#include <stdio.h>
#include <stdlib.h>



int max(int a, int b){

	if (a > b) return a;
	else return b;

}

int recSumAtRow(int **rowData, int rowNum){

	int i, j;

	for (i = 0; i < 15; i++)
		{
			rowData[rowNum][i] += max(rowData[rowNum + 1][i], rowData[rowNum + 1][i + 1]);
		}
		/*
		for (i = 0; i <= rowNum; ++i){
  			for (j = 0; j <= rowNum; ++j){
  				printf("%d\t", rowData[i][j]);
  			}	
  		printf("\n");
		}
		*/

		//base case
		if (rowNum == 0) 
			return rowData[rowNum][0];
		//Recursive case
		else return recSumAtRow(rowData, rowNum - 1);

}

int main(){

  int i, j;
  int rows, cols;
  FILE *ptr_file;


  int **triangle = malloc(1000 * sizeof(int*));
  	
  	for(i = 0; i < 1000; i++)
  		triangle[i] = malloc(sizeof(int)*1000);


  ptr_file = fopen("Data.txt", "r");
  //check if the file opens
  if(!ptr_file){
  	printf("Cannot open file\n");
  	return 0;
  }

	for(i = 0; i < 15; i++){
    	for(j = 0; j < 15; j++){
  			//Use lf format specifier, %c is for character
      		if( j <= i) fscanf(ptr_file, "%d", &triangle[i][j]); 
        	else triangle[i][j] = 0;
      }
  }

  fclose(ptr_file);

  for (i = 0; i < 15; ++i){
  	for (j = 0; j < 15; ++j){
  		printf("%d\t", triangle[i][j]);
  		}
  	printf("\n");
	}
	printf("\nmax = %d\n", recSumAtRow(triangle, 15 - 2) );
}