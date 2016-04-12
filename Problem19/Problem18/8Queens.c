#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define NQueen 6

int CheckCol(int Board[NQueen][NQueen], int hold_x, int hold_y){
	int i, j;
	for(i = 0; i < NQueen; i++){
			if(i != hold_x){
				if(Board[i][hold_y] == 8)
					return FALSE;
		}
	}
	//printf("TRUE_Col\n");
	return TRUE;
}

int CheckRow(int Board[NQueen][NQueen], int hold_x, int hold_y){
	int i, j;
	for(j = 0; j < NQueen; j++){
			if(j != hold_y){
				if(Board[hold_x][j] == 8)
					return FALSE;
		}
	}
	//printf("TRUE_Row\n");
	return TRUE;
}

int CheckDiag(int Board[NQueen][NQueen], int hold_x, int hold_y){

	int i, j = hold_y;
	//Check right and down
	for (i = hold_x; i < NQueen && j < NQueen; i++){
		if(i != hold_x && j != hold_y){
			if(Board[i][j] == 8){
				return FALSE;
			}
		}
			j++;
	}
	//Check right and up
	j = hold_y;
	for (i = hold_x; i < NQueen && j >= 0; i++){
		if(i != hold_x && j != hold_y)
			if(Board[i][j] == 8){
				return FALSE;
			}
			j--;
	}
	//Check left and up
	j = hold_y;
	for (i = hold_x; i >= 0 && j >= 0; i--){
		if(i != hold_x && j != hold_y)
			if(Board[i][j] == 8){
				return FALSE;
			}
			j--;
	}
	//Check left and down
	j = hold_y;
	for (i = hold_x; i >= 0 && j < NQueen; i--){
		if(i != hold_x && j != hold_y)
			if(Board[i][j] == 8){
				return FALSE;
			}
			j++;
	}
	//printf("TRUE_Diag\n");
	return TRUE;

}

printBoard(int Board[NQueen][NQueen]){

	int i, j;

	for(i = 0; i < NQueen; i++){
		for(j = 0; j < NQueen; j++){
			if(Board[i][j] == 8){
				printf("Q  ");
			}
			else printf("*  ");
		}
		printf("\n");
	}
	printf("\n\n");

}

int MakeAMove(int Board[NQueen][NQueen], int Queen){


	int i, j;

	if(Queen == NQueen){
		return TRUE;
	}

	//check if the cell is empty
	for(i = 0; i < NQueen; i++){
		for (j = 0; j < NQueen; j++){
			if(Board[i][j] == 0){
				Board[i][j] = 8; //if it is place the queen
				if( (CheckDiag(Board, i, j) == TRUE) 
				&& (CheckCol(Board, i, j) == TRUE) 
				&& (CheckRow(Board, i, j) == TRUE) ){ //if it is safe, go on
					//printBoard(Board);
					Queen++;
					//printf("Queen = %d\n", Queen);
					//getchar();
					if(MakeAMove(Board, Queen) == TRUE)	
						return TRUE;
						Board[i][j] = 0; //back track
						Queen--;
				}
				else Board[i][j] = 0; //reset to 0 if illegal
			}
		}
	}
			
	return FALSE;

}

void ResetBoard(int Board[NQueen][NQueen]){

	int i, j;
	for(i = 0; i < NQueen; i++){
		for(j = 0; j < NQueen; j++){
			Board[i][j] = 0;
		}
	}

}

int main(){

	int Board[NQueen][NQueen], i, j;

	ResetBoard(Board);

	//Board[0][0] = 8;
	//Board[hold_x][hold_y] = 8;
	printBoard(Board);
	//printf("%d\n", CheckRow(Board, hold_x, hold_y) );
	//printf("%d\n", CheckCol(Board, hold_x, hold_y) );
	//printf("%d\n", CheckDiag(Board, hold_x, hold_y) );

	for(i = 0; i < NQueen/2; i++){
		for(j = 0; j < NQueen/2; j++){
			Board[i][j] = 8; //put queen
			//printf("i = %d\n", i);
			//printf("j = %d\n", j);
			//printBoard(Board);
			//getchar();
				if(MakeAMove(Board, 1) == TRUE ) printBoard(Board);
				ResetBoard(Board);
		}
	}

}