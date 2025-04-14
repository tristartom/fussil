#include <stdio.h>
#include <unistd.h>

void inc_file() {
  int val;
  FILE* f = fopen("counter.txt", "r+");
  fscanf(f, "%d", &val); rewind(f);
  fprintf(f, "%d\n", val + 1);
  fclose(f);}

int main() {
  if (fork() == 0) {
    for (int i = 0; i < 1000; i++) 
      inc_file();
  } else {
    for (int i = 0; i < 1000; i++) 
      inc_file();
  }}
