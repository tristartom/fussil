#include <string.h>
#include <unistd.h>
#include <stdio.h>

void* shared_malloc(size_t size);

int main(void) {
  int* shared_bal = (int *)shared_malloc(sizeof(int));
  (*shared_bal) = 0; 
  fork();
  for(int i=0; i<1000000; i++)
    (*shared_bal)++;
  printf("final:%d\n", (*shared_bal));
}

