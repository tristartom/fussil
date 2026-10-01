#include <string.h>
#include <unistd.h>
#include <stdio.h>

void* shared_malloc(size_t size);
void spinlock_init();
void spinlock_acquire();
void spinlock_release();

int main(void) {
  int* shared_bal = (int *)shared_malloc(sizeof(int));
  spinlock_init();

  (*shared_bal) = 0; 
  fork();
  for(int i=0; i<100000; i++){
    spinlock_acquire();
    (*shared_bal)++;
    spinlock_release();
  }
  printf("final:%d\n", (*shared_bal));
}

