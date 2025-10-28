#include<unistd.h>
#include<stdio.h> 
#include <fcntl.h>
#include <sys/stat.h> //stat

char access_w(char* filename){
  struct stat buf;
  if(stat(filename, &buf) < 0) {printf("error"); return 1;} 
  return (buf.st_mode & S_IWUSR) ? 'w' : '-';
}

char buf2[] = "GOOD";

void write_to_file(char* filename, char* permname){
  if (access_w(permname) == 'w'){
    int fd = open(filename, O_CREAT|O_TRUNC|O_RDWR);
    write(fd, buf2, 10);
    close(fd);
  } else {
    printf("access failed\n");
  }
}

int main(void){
  write_to_file("fileRW.txt", "permRW.txt");
}

