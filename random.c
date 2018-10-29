#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int randgen(){
  int file = open("/dev/random", O_RDONLY);
  int *number = (int *)malloc(sizeof(int));
  read(file,number,sizeof(int));
  printf("%d\n", *number);
  int num = *number;
  free(number);
  if(close(file) < 0){
    printf("ERROR\n");
    _exit(0);
  }
  return num;
}

int main(){
  return randgen();
}
