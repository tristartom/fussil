#include <unistd.h>
#include <sys/mman.h>

/*
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
