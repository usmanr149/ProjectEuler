#include <stdio.h>
#include<time.h>
int main(){

  int count = 1, hold = -1, hold_n;
  long int i, n = 2;
  clock_t begin, end;
  double time_spent;

  /* i = 113383; */
  /* printf("i = %ld\n", i); */
  /* while(i!=1){ */
  /*   if(i%2 == 0) i=i/2; */
  /*   else i=3*i+1; */
  /*   printf("i = %ld\n", i); */
  /*   getchar(); */
  /*   count++; */
  /* } */
  /* printf("count = %d\n", count); */

  begin = clock();
  while(n<=1000000){
    i=n;
    while(i!=1){
      if(i%2 == 0) i=i/2;
      else i=3*i+1;
      count++;
    }
    if(count > hold) { hold = count; hold_n = n; }
    //printf("n = %ld\n", n);
    //printf("count = %d\n", count);
    count = 1;
    n++;
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time_spent = %f\n", time_spent);
  //printf("\ncount = %d\n", count);
  printf("hold = %d\n", hold);
  printf("hold_n = %d\n", hold_n);
 
}
