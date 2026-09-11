// overflow.c
//#include <string.h>
#include <stdio.h>

void scopy(char* dest, char* src){
  for (int i=0; src[i] != '\0'; i++) dest[i]=src[i];
}

void foo(char * arg){
  char buf[4]; 
  scopy(buf, arg);  // No bounds checking
  printf("%s\n", buf);
}

int main(int argc, char **argv) {
  if (argc > 1) foo(argv[1]);
}
