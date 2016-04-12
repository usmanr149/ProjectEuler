#include <stdio.h>
#include <stdlib.h>
int main(){

  FILE *ptr_file;
  int i=0,j,*ptr,size;
  char *code; 

  ptr_file = fopen("numbers.dat", "r");
  if(!ptr_file){
    printf("Cannot open file\n");
    return 1;
  }

  fseek(ptr_file, 0, SEEK_END); //puts the cursor at the end of the file, 
  long f_size = ftell(ptr_file);//then ftell tells you where the cursor is
  fseek(ptr_file, 0, SEEK_SET); // puts the cursor back at the beginning of the file so it can be read
  //long int size = malloc(f_size);
  
  code=(char*)malloc(f_size*sizeof(char));
  ptr=(int*)malloc(f_size*sizeof(int));

  while ((j = fgetc(ptr_file))!=EOF){
    if(j!='\n'){
    code[i] = (char)j;
    ptr[i] = code[i] - '0';
    //printf("code[%d] = %c\n", i, code[i]);
    //printf("ptr[%d] = %d\n", i, ptr[i]);
    //getchar();
    i++;
    }
  }
  printf("ptr[%d] = %d\n", i, ptr[i]);
  printf(" i = %d\n", i);
  size = i+1;
  fclose(ptr_file);
  free(code); //When you are done with the memory, you need to free it so that the space can be given out by future calls to malloc().
  /* for(i = 0; i < size; i++){ */
  /*   printf("ptr[%d] = %d\n", i, ptr[i]); */
  /* } */
  //getchar();
  int zig = 13, array[20],k;
  long int hold = 0, multiple = 0;
  for(i = 0; i < size-zig; i++){
    multiple = ptr[i];
    for(j = i+1; j<i+zig; j++){
      multiple *= ptr[j];
      }
    //printf("i = %d\n", i);
    if(multiple > hold){
      hold = multiple;
      for(k = i; k<i+zig; k++){
	array[k-i] = ptr[k];
	//printf("hold = %d\n", hold);
	//printf("array[%d] = %d\n", k-i, array[k-i]);
	//printf("ptr[%d] = %d\n", k, ptr[k]);
      }
      //getchar();
    }
  }
  printf("hold = %ld\n", hold);
  for(j = 0; j<zig; j++){
    printf("array[%d] = %d\n", j, array[j]);
    }

  free(ptr);

}
