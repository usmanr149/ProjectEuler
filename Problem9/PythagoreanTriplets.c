#include <stdio.h>

int main(){

  int a=0,b=0,c=0,m=1,n=0;
  int target = 1000;
  //m>n
  
  for(n=1;n<501;n++){
    for(m=n+1;m<501;m++){
	a=m*m-n*n;
	b=2*m*n;
	c=m*m+n*n;
	if(a+b+c == target){
	  printf("a+b+c = %d\n", a+b+c);
	  printf("a = %d\n", a);
	  printf("b = %d\n", b);
	  printf("c = %d\n", c);
	  return 0;
	}
    }
  }
  
}
