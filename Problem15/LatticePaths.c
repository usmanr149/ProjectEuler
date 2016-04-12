#include <stdio.h>
#define Length 2

int start(int x, int y){

  if(x == 0 && y == 0) return 1;
  int count = 0;

  if(x > 0){
    //printf("(x, y) = (%d, %d)\n", x-1, y);
    //getchar();
    count+=start(x-1, y);
    //return 1;
  }

  if(y > 0){
    //printf("(x, y) = (%d, %d)\n", x, y-1);
    //getchar();
    count+=start(x, y-1);
    //return 1;
  }
  
  //printf("Here (x, y) = (%d, %d)\n", x, y);
  //printf("count = %d\n", count);

  return count;
}

int main(void){

  int i, l = 20; 
  long long int j = 1;
  
  for(i= l*2; i>l; i--){
    j=j*i;
    if(i%2 == 0) j=j*2/i;
  }

  printf("j = %lld\n", j);
  
  if(l>=4)
    for(i=2; i<=(l/2); i++) j=j/i;

  printf("j = %lld\n", j);
  
  printf("The number of ways to reach the end is %d\n", start(l,l));
  return 0;
}
