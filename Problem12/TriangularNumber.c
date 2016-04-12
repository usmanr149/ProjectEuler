#include <stdio.h>
#include <math.h>

int CheckDivisor(int p){

  int SqRd = sqrt(p);
  int i =1, total = 0;
  while(i <= SqRd){
    if(p%i == 0){
      if(i == (p/i) || i == 1) total++;
      else total = total + 2;
    }
    i++;
  }
  return total;
}

int main(){

  int i = 1, div, p = 1;

  printf("Enter the number of divisors: ");
  scanf("%d", &div);

  while(CheckDivisor(i) < div){
    p++;
    i = p*(p+1)/2;
  }
  printf("i = %d\n", i); 

}
