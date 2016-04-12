#include "foo.h"
#include<stdio.h>
#include <math.h>

long int gcd(long int a, long int b){
  
  long int h;
  
  //need a>b, so switch if this not true
  if(b>a){
    h=a;
    a=b;
    b=h;
  }
    return b == 0 ? a : gcd(b, a%b);
}

int main(){

  long int p, q, n, phi, e=3, gcdm = 0;
  long int message;
  long int zig = 100000; //Make this arbitrarily high
  long int sum = 0;
  long int total = 0;
  
  p = 1009;
  q = 3643;
  
  n = p*q;
  
  phi = (p-1)*(q-1);
  
  for(e = 2; e < phi; e++){
    gcdm = gcd(e,phi);
    if(gcdm == 1){

      total =  (1+gcd(e-1,p-1))*(1+gcd(e-1,q-1));
      if(total <= zig){
	if(zig > total) sum = 0; 
	zig = total; 
	sum+=e; 
      }
    }
  }
  printf("sum = %ld\n", sum);
}
