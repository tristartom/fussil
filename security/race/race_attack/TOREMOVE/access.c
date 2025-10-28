#include<unistd.h>
#include<stdio.h> 
#include <fcntl.h>
char buf2[] = "ABCDEFGHIJ";
int main(void){

  if (access("./file.txt", W_OK)){
    int fd = open("./file.txt", O_CREAT|O_TRUNC|O_RDWR);
    write(fd, buf2, 10);
    close(fd);    
  } else {
    printf("access failed\n");
  }
}

