#include <stdio.h>

int check( int temp)
{
  int i,n;

  for(i=10;i<21;i++)
    {
      n = temp%i;
      if (n != 0){
	return 0;
	break;
      }
    }
  printf("temp is %d\n", temp);
  getchar();
  return 1;
}

int main(){

  int temp;
  temp = 20;

  while( check(temp) == 0 ){
    temp++; 
  }
}
