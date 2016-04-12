/*
 * C program to print all possible subsets 
 * with k element in each subset
 */
#include <stdio.h>
 
/*  Function to generate subset  */
void subset(int arr[], int subarray[], int start, 
    int arraysize, int index, int sub)
{
    int j, i;
    //if the array of the size of subarray has been built
    if(index == sub){
        for (j = 0; j < sub; ++j){
            printf("%d", subarray[j]);
        }
            printf("\n");
            return;
        }
    //start at the start
        //start is initially 0
        //index is initially 0
        //for (i = start; i <= arraysize 
        //    && arraysize - i + 1 >= sub - index; ++i)
        for(i = start; i <=arraysize; i++)
        {
            /* code */
            subarray[index] = arr[i];
            subset(arr, subarray, i+1, arraysize, index+1, sub);
        }

}
/*  End of subset()  */
 
/*  Function to print the subset  */ 
void printsubset(int arr[], int arraysize, int sub)
{
    int subarray[sub];
    subset(arr, subarray, 0, arraysize - 1, 0, sub);
}
/*  End of printsubset()  */
 
/*  The main() begins  */
int main()
{
    int arr[20], sub, arraysize, i;
    printf("Enter the number of input : ");
    scanf("%d", &arraysize);
    printf("\nEnter the integers: \n");
    for (  i = 0; i < arraysize; i++)
    {
	scanf("%d", &arr[i]);
    }
    printf("Enter value of subset: ");
    scanf("%d", &sub);
    printsubset(arr, arraysize, sub);
    return 0;
}