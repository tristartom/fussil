#include <stdio.h>
#include <unistd.h>

void inc_file() {
  int val;
  FILE* f = fopen("counter.txt", "r+");
  fscanf(f, "%d", &val); rewind(f);
  fprintf(f, "%d\n", val + 1);
  fclose(f);}

int main() {
  fork();
  inc_file(); //0->1; 1->2
  inc_file(); //2->3; 3->4
  inc_file(); 
  inc_file();
}

