#include <stdio.h>

int factorial(int n);
int main(){

	int num, mult;
	printf("Enter a number\n");
	scanf("%d", &num);

	mult = factorial(num);
	printf("%d\n", mult);

}

int factorial(int n){
	if(n == 0)
		return 1;
	else 
		return n*factorial(n-1);
}
