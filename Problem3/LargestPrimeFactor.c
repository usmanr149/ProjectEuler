#include<stdio.h>
#include<time.h>
#include<math.h>

int CheckPrime(long int i){

  long int j = 0;
  long int i_sqrt = sqrt(i);

  if(i%2 == 0) return 0;

  for(j=3; j <= i_sqrt; j+=2){
    if(i%j == 0) return 0;
  } 
  return 1;
}

int main(){
  long int i;
  int j = 3;
  clock_t begin, end;
  double time_spent;

  i =  600851475143;

  begin = clock();
  while(j<=sqrt(i)){
    //printf("j = %d\n", j);
    if(CheckPrime(j) == 1){
      if(i%j == 0){
	printf("%ld is divisible by the prime %d\n", i, j);
	//getchar();
      }
    }
    j+=2;
    //else printf("%d is not prime\n", i);
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time_spent = %f\n", time_spent);
  
}
