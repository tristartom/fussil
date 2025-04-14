#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

//locked when lock == 0
//unlocked when lock != 0

void slock_acquire(int * lock){
  while(*lock == 0);
  *lock = 0;
}

void slock_release(int * lock){
  *lock = 1;
}

void* shared_malloc(size_t size){
  int prot = PROT_READ | PROT_WRITE;
  int flag = MAP_SHARED | MAP_ANONYMOUS;
  return mmap(NULL, size, prot, flag, -1, 0);
}

void inc_file() {
  int val;
  FILE* f = fopen("counter.txt", "r+");
  fscanf(f, "%d", &val); rewind(f);
  fprintf(f, "%d\n", val + 1);
  fclose(f);}

int* lock = NULL;
void safe_inc_file() {
  if (lock == NULL){
    lock = (int *)shared_malloc(sizeof(int));
    *lock = 1;
  }
  slock_acquire(lock);
  inc_file();
  slock_release(lock);
}

int main() {
  fork();
  safe_inc_file();
  safe_inc_file();
  safe_inc_file();
  safe_inc_file();
}
