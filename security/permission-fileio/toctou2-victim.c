#include<unistd.h>
#include<stdio.h> 
#include<fcntl.h>
#include<sys/stat.h> //stat

char buf2[6];

int access2_r(char* filename){
  int fd = open(filename, O_RDONLY);
  return fd <= 0; 
}

int main(int argc, char** argv){
//  if (access(argv[1], R_OK) != 0){ // TOC
  if (access2_r(argv[1]) != 0){ // TOC
    printf("no read permission\n");
    return 1;
  }
  //access allowed
  int fd = open(argv[1], O_RDONLY); //TOU
  if (fd < 0) {printf("open error"); return -1;}
  while(read(fd, buf2, 1) == 1)
    printf("%c", buf2[0]); 
  close(fd);
}
