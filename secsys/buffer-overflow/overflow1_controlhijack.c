#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void bar(void){
  printf("bar\n");
}

void foo(long offset, long code_address){
  long buf[0];
  buf[offset] = code_address;
  printf("foo\n");
}

int main(int argc, char **argv) {
  if (argc < 2) return 1;
  long offset = strtol(argv[1], NULL, 10);
  long address = strtol(argv[2], NULL, 16);
  foo(offset, address);
  printf("main\n");
}
