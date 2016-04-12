#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

long long int sumPrime=0;

int isPrime(long long int n){

  long long int i, half=sqrt(n);
  //printf("half = %lld\n n=%lld\n", half, n);

  for(i=3; i<=half; i+=2){
    if(n%i==0) return 0;
  }return 1;

}

int main(){

  long long int n,i,count=0;
  long long int sumofPrimes=0;

  //sumofPrimes = (long long int *)malloc(sizeof(long long int));
  
  printf("Enter a number:\n");
  scanf("%lld", &n);
  

  /* if(isPrime(n)==1) */
  /*   printf("%d is a prime\n", n); */
  /* else printf("%d is not a prime\n", n); */

  //printf("2 is a prime\n");
  //just try all the odd numbers in the range.
  /* If you want to put in 10, then 3,5,7 and 9 are checked. */
  /*   If you want to put in 11, then 3,5,7,9 and 11 are checked. */
  for(i=3; i <= n; i+=2){
    if(isPrime(i)==1){
      sumofPrimes+=(i);
      count++;
      //printf("%lld is a prime\n", i);
  }
  }
  printf("Total number of primes <= %lld = %lld\n", n, count+1);
  printf("Sum is = %lld\n", sumofPrimes+2);
  //free(sumofPrimes);
}
