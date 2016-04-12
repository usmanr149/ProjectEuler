#include <stdio.h>

long int reverse(long int i){

  long int reverse = 0;

  while(i != 0){
    reverse = reverse * 10;
    reverse = reverse + i%10;
    i = i/10;
  }
  return reverse;

}

int check(long int rev){

  long int p;

  while(rev != 0){
    p = rev%10;
    if(p%2 == 0) return 0;
    rev = rev/10;
      }
  return 1;

}

int main(){

  long int i,j, count = 0,zig;

  /* printf("Enter a number: "); */
  /* scanf("%d", &i); */

  /* if(i%10 != 0) */
  /*     j = reverse(i); */
  /*   if(check(i+j) == 1) */
  /*     count++; */

  for(i=1000; i<10000; i++){
    if(i%10 != 0 && i%10==1 && i/1000==2){
      j = reverse(i);
      if(check(i+j) == 1){
	printf("i = %ld\n", i);
	printf("j = %ld\n", j);
	printf("i+j = %ld\n", i+j);
	getchar();
	count++;
      }
    }
  }
  
  printf("count = %ld\n",count);

}
