#include <stdio.h>
int main(){

  int a,b;
  printf("Enter a number: ");
  scanf("%d", &a);

  printf("Enter a number: ");
  scanf("%d", &b);
  
  gcd(a,b);


}

int gcd(int a, int b) {
    int y = 0;
    int x = 0;
 
    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }
 
    while (x % y != 0) {
        int temp = x;
        x = y;
        y = temp % x;
    }
    printf("y = %d\n", y);
    return y;
}
