#include <unistd.h>
#include <sys/mman.h>

/*
- Why spinlock_unsafe.c is unsafe

| Step | Process A                                  | Process B                                  |
| ---- | ------------------------------------------ | ------------------------------------------ |
| 1    | Reads `*lock == 1` and exits the loop      |                                            |
| 2    |                                            | Reads `*lock == 1` and exits the loop      |
| 3    | Writes `*lock = 0`;enters critical section |                                            |
| 4    |                                            | Writes `*lock = 0`; enters critical section|

void* shared_malloc(size_t size){
  int prot = PROT_READ | PROT_WRITE;
  int flag = MAP_SHARED | MAP_ANONYMOUS;
  return mmap(NULL, size, prot, flag, -1, 0);
}
*/

void* shared_malloc(size_t size);

int* lock = NULL;
void spinlock_init(){
  lock = (int *)shared_malloc(sizeof(int));
  *lock = 1;
}
void spinlock_acquire(){
  while(*lock == 0);
  *lock = 0;
}

void spinlock_release(){
  *lock = 1;
}
