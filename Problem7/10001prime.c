#include <stdio.h>
#include <math.h>

int isPrime(int n){

  int i, half=sqrt(n);

  for(i=3; i<=half; i+=2){
    if(n%i==0) return 0;
  }return 1;

}

int main(){

  int count = 1, i=1, n = 1000000, userInput;

  printf("Enter the ith prime to evauate:\n");
    scanf("%d", &userInput);
  
    if(userInput == 1)
      printf("The 1st prime is 2\n");

    while(count <= userInput){
      i+=2;
    if(isPrime(i)==1){
      count++;
      if ( count == userInput ){
	printf("The %d prime is %d\n", count, i);
	return 0;
      }
    }
   }
}
