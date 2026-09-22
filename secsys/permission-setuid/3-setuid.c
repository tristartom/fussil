#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char** argv){
  int ruid=getuid();
  int euid=geteuid();
  int fd;

  printf("Before setuid:\n");

  printf(" Real UID: %d\n", getuid());
  printf(" Effective UID: %d\n", geteuid());
  fd = open(argv[1], O_RDONLY); //TOU
  printf(" Open fd: %d\n", fd);

  // Try to change effective UID to 0 (root)
  if (setuid(ruid) == -1) perror("setuid failed");

  printf("\nAfter setuid():\n");

  printf(" Real UID: %d\n", getuid());
  printf(" Effective UID: %d\n", geteuid());
  fd = open(argv[1], O_RDONLY); //TOU
  printf(" Open fd: %d\n", fd);
}

