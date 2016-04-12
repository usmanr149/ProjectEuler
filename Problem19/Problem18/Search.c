#include<stdio.h>
int main(){

	int a[10], i, n, m, c, l, u;
	printf("Enter the size of an array:\n");
	scanf("%d", &n);

	printf("Enter the elements of the array:\n");
	for (i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d", &a[i]);
	}

	printf("Enter te number to be searched\n");
	scanf("%d", &m);

	l = 0, u = n - 1;
	c = binary(a, n, m, l, u);
	if(c == 0)
		printf("Number is not found.\n");
	else
		printf("Number is found.\n");
	return 0;

}

int binary(int a[10], int n, int m, int l, int u){
	int mid, c = 0;
	//m is the number we are looking for
	printf("l = %d\n", l);
	printf("u = %d\n", u);
	getchar();
	if(l<=u){
		mid = (l+u)/2;
		if(m==a[mid])
			c=1;
		else if(m<a[mid])
			return binary(a, n, m, l, mid - 1);
		else
			return binary(a, n, m, mid + 1, u);
	}
	else
		return c;
}