#include<stdio.h>
#include<math.h>
#define true 1
#define false 0
#define M 0.30102999566

long long int binary(long long int i){
  // i = 23
  long long int n, bina = 0;

  while(i > 0){
    n = log10(i)/M; // 4, 2
    bina += powl(10, (double)n); // 10000, 10100
    i = i - powl(2, (double)n); // 7, 2
  }
  return bina;
}

long long int CheckPalindrome(long long int i){

  long long int j = 0, hold, remainder;
  hold = i;

  while(i != 0){
    remainder = i%10;
    j = j*10 + remainder;
    i = i/10;
  }

  if(j == hold) return true;
  else return false;

}

int main(){

  long long int i = 584;
  long long int j;
  long long int sum = 0;
  long long int limit = 1000000;

  printf("binary = %lld\n", binary(limit - 1));
  getchar();

  for(j = 1; j<limit; j+=2){
    if(CheckPalindrome(j) == true)
      if(CheckPalindrome(binary(j)) == true){
	sum+=j;
	printf("j = %lld\n", j);
	printf("binary = %lld\n", binary(j));
	printf("sum = %lld\n", sum);
	getchar();
      }
  }
  printf("sum = %lld\n", sum);
}

//9223372036854775807
//10011100010000
//10011100010000
//11000011010011111
//10010000000001001
