#include <string.h>
#include <unistd.h>
#include <stdio.h>

void* shared_malloc(size_t size);

int main(void) {
//https://stackoverflow.com/a/76122977/486720
  int* shared_bal = (int *)shared_malloc(sizeof(int));
  int* shared_lock = (int *)shared_malloc(sizeof(int));

  * shared_lock = 3;
  * shared_bal = 13; 
  if (fork() == 0) {
    if(*shared_bal>12){
      * shared_lock = 4;
      printf("One book ordered\n");
      * shared_bal -= 12;}
  } else {
    if(*shared_bal>12){
      while(*shared_lock == 3);
      printf("One book ordered\n");
      * shared_bal -= 12;
    }
  }
}

