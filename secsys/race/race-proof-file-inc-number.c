#include <stdio.h>
#include <unistd.h>

//locked when lock == 0
//unlocked when lock != 0

void spinlock_init();
void spinlock_acquire();
void spinlock_release();

void inc_file() {
  int val;
  FILE* f = fopen("counter.txt", "r+");
  fscanf(f, "%d", &val); rewind(f);
  fprintf(f, "%d\n", val + 1);
  fclose(f);}

void safe_inc_file() {
  spinlock_acquire();
  inc_file();
  spinlock_release();
}


int main() {
  spinlock_init();
  fork();
  safe_inc_file();
  safe_inc_file();
  safe_inc_file();
  safe_inc_file();
}

