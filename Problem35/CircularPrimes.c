#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int CheckPrime(int pr){

  int limit = sqrt((double)pr);
  int i;

  //printf("limit = %d\n", limit);
  //getchar();

  if(pr%2 == 0) return FALSE;

  for(i = 3; i <= limit; i+=2){
    if(pr%i == 0) return FALSE;
  }

  return TRUE;
}

int rotate(int a){
  
  int digits = log10((double)a);
  int Multiplier = powl(10, (double)digits);

  int hold = a%10; //
  
  int b = hold*Multiplier + a/10;

  return b;

}

int checkallrotations(int a){

  int i , rot;

  
  //Get the length of the number.
  int length = log10((double)a);
  //printf("length = %d\n", length);
  //printf("a check = %d\n", a);
  rot = a;

  for(i = 0; i < length; i++){
    rot = rotate(rot);
    //printf("rot check = %d\n", rot);
    if(CheckPrime(rot) == FALSE) return FALSE;
  }

  return TRUE;

}

int main(){

  int a, total = 1;
  
  
  /* if(CheckPrime(29) == TRUE) printf("tis a prime\n"); */
  /* else printf("No, its not a prime\n"); */
  /* if(checkallrotations(29) == TRUE) printf("yeah\n"); */
  /* else printf("Nah\n"); */
  

  //first find the primes
  for( a = 3; a <= 1000000; a+=2){
    if(CheckPrime(a) == TRUE)
      if(checkallrotations(a) == TRUE){
  	total++;
  	printf("a = %d\n", a);
  	//getchar();
      }
  }

  printf("total = %d\n", total);

}
