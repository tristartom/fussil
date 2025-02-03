#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
  int fd;
  char *v[2];

  fd = open("/etc/zzz", O_RDWR | O_APPEND);        
  if (fd == -1) {
     printf("Cannot open /etc/zzz\n");exit(0);
  }

  printf("fd is %d\n", fd);
  // protection: close(fd);
  // Permanently disable the privilege by making the
  // effective uid the same as the real uid
  setuid(getuid());                                

  // Execute /bin/sh
  v[0] = "/bin/sh"; v[1] = 0;
  execve(v[0], v, 0);
}
