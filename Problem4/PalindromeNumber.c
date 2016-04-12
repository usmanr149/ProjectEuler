#include <stdio.h>

long int reverse = 0;

int check( int temp)
{
  reverse = 0;

  while( temp != 0 )
    {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp = temp/10;
    }

}

int main()
{

  int i, j, f, g;
  long int temp, n, Holder = 0;


  for( i = 100; i<999; i++){
    for( j = 100; j<999; j++){
	 n = i*j;
	 temp = n;
	check(temp);
	if ( n == reverse ){
	  if(n > Holder){
	    Holder = n;
	  f = i;
	  g = j;
	  }
	}
    }
  }

  printf("%ld = %d * %d is the largest palindrome\n", Holder, f, g);

  return 0;
}
