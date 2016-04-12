#include<stdio.h>

void subset(int arr[], int subarray[], int start, 
	int arraysize, int index, int sub){

	int i, j;
	if(index == sub){
		for(j = 0; j < sub; j++){
			printf("%d", subarray[j]);
		}
		printf("\n");
		return;
	}

	//&& arraysize - i + 1 >= sub - index
	for(i = start; i <= arraysize ; i++){
		//i+1 is the start
		subarray[index] = arr[i];
		subset(arr, subarray, i+1, arraysize, index+1, sub);
	}

}

void printsubset(int arr[], int arraysize){
	int i;
	int subarray[arraysize];
	for (i = 1; i <= arraysize; i++)
	{
		/* code */
		subset(arr, subarray, 0, arraysize - 1, 0, i);
	}

}

int main(){
	int arr[20], arraysize, sub, i;
	printf("Enter the size of array\n");
	scanf("%d", &arraysize);
	printf("Enter the element of the array\n");
	for(i = 0; i < arraysize; i++){
		scanf("%d", &arr[i]);
	}
	printf("\n\n");
	printsubset(arr, arraysize);
	return 0;
}