#include<stdio.h>
#include <math.h>

long int Midstep(long int a, long int b, long int n){

  long int c;

  if(b > 1){
    c = powl(a, 2.0);
    c = c%n;
    c = c * Midstep(a, b-2 , n);
  }
  else{
    if(b%2 == 1) c = a%n;
    else{ c = powl(a, 2.0); 
    c = c%n;
    }
  }
  if(c > n) c=c%n;
  return c;
}

long int ModularExponentian(long int a, long int b, long int n){

  long int c;
  
  if(b%2 == 1){
    c = powl(a, 2.0);
    c = c%n; 
    
    if(b > 2){
      c = c*Midstep(a, b-2 , n);
    }
  }
  
  else c = Midstep(a, b-2 , n);
  c = c%n;
  //printf("c = %ld\n", c);
  return c;
  
}

/* int main(){ */

/*   int a, b, c; */
  
/*   a=1009; */
/*   b=3643; */
/*   c=13; */

/*   ModularExponentian(a, b ,c); */

/* } */
