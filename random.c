#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int randgen(){
  int file = open("/dev/random", O_RDONLY);
  int *number = (int *)malloc(sizeof(int));
  read(file,number,sizeof(int));
  //printf("%d\n", *number);
  int num = *number;
  free(number);
  if(close(file) < 0){
    printf("ERROR\n");
    _exit(0);
  }
  return num;
}

int main(){
  int file = open("nums.txt", O_RDWR | O_CREAT, 0666);
  int* nums = (int*)malloc(10*sizeof(int));
  for(int i = 0;i < 10;i++){
    nums[i] = randgen();
  }
  printf("\n");
  for(int i = 0;i < 10;i++){
    printf("%d\n",nums[i]);
  }
  write(file,&nums,sizeof(*nums));
  /*
  for(int i = 0;i < 10;i++){
    write(file,&nums[i],sizeof(int));
  }
  */
  file = open("nums.txt", O_RDWR);
  int* copy = (int*)malloc(10*sizeof(int));
  read(file,&copy,sizeof(*copy));
  /*
  for(int i = 0;i < 10;i++){
    read(file,&copy[i],sizeof(int));
  }
  */
  printf("\n");
  for(int i = 0;i < 10;i++){
    printf("%d\n",copy[i]);
  }
  return 0;
}
