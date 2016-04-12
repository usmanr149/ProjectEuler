#include <stdio.h>

int sum(int n);

int main(){

	int num, add;
	printf("Enter a positive integer\n");
	scanf("%d", &num);
	add=sum(num);
	printf("%d\n", add);

}

int sum(int n){
	if(n==0)
		return n;
	else
		return n + sum(n-1);
}