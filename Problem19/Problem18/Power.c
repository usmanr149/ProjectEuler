#include<stdio.h>

int power(int i, int j);
int main(){

	int num, expo, ans;
	printf("Enter a number\n");
	scanf("%d", &num);
	printf("Enter a power to raise it to\n");
	scanf("%d", &expo);
	ans = power(num, expo);
	printf("%d\n", ans);


}

int power(int i, int j){

	if(j == 0)
		return 1;
	else
		return i*power(i, j-1);

}