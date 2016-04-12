#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

char actualsum[255];

int sumlargeNumber(char s1[255], char s2[255]){

  int l1 = 0, l2 = 0, sum[255], k = 0, carry = 0, zig = 0;
  
  int num1[255], num2[255];
   
  for (l1 = 0; s1[l1] != '\0'; l1++)
    num1[l1] = s1[l1] - '0';

  for (l2 = 0; s2[l2] != '\0'; l2++)
    num2[l2] = s2[l2] - '0';

  int i = l1 - 1;
  int j = l2 - 1;

  for(;i>=0 && j>=0; i--, j--, k++){
    sum[k] = (num1[i] + num2[j] + carry)%10;
    carry = (num1[i] + num2[j] + carry)/10;
  }
  
  if(l1 > l2 ){
    while(i>=0){
      sum[k++] = (num1[i] + carry)%10;
      carry = (num1[i] + carry)/10;
      i--;
    }
  }
  else if(l2 > l1){
    while(j>=0){
      sum[k++] = (num2[j] + carry)%10;
      carry = (num2[j] + carry)/10;
      j--;
    }
  }

  if(carry > 0)
    sum[k++] = carry;

  for (k--; k >= 0; k--){
    actualsum[zig] = sum[k] + '0';
    zig++;
  }

}

int main(){

  FILE *ptr;
  char j;
  char code[255][255];
  int i, k;
  long int multiple = 0;
  int l1, l2, col;
  char sum[255], s1[255];
  int x, y, g;

  ptr = fopen("numbers.dat", "r");
  if(!ptr){
    printf("Cannot open file\n");
    return 0;
  }

  while((j = fgetc(ptr))!=EOF){
    if(j=='\n') { i=0; col++;}
    if(j!='\n'){
      code[col][i] = j;
      i++;
    }
  }

  for(x = 0; x<100; x++){
    for(y = 0; y<50; y++){
      s1[y]='\0';
      s1[y] = code[x][y];
    }
    sumlargeNumber(sum, s1);
    for(g=0;g<256;g++){
      if(actualsum[g] != '\0'){
	sum[g] = actualsum[g] ;
	}
    }
  }

  for(x=0;x<100;x++){
    if(sum[x] == '0' || sum[x] == '1' || sum[x] == '2' || sum[x] == '3' || sum[x] == '4' || sum[x] == '5' || sum[x] == '6' || sum[x] == '7' || sum[x] == '8' || sum[x] == '9'){
      printf("%c", sum[x]);
    }
  }
  printf("\n");
  
}
