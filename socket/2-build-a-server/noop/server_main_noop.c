#include "csapp.h"
int main(int argc, char **argv) {
  int port = atoi(argv[1]);
  int listenfd, connfd;
  struct sockaddr_in clientaddr;
  socklen_t clientlen = sizeof(clientaddr);
  listenfd = open_listenfd(port);
  for(int i = 0; i < 5; i++){
//  while (1) {
    connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
    printf("Socket connected: %d\n", connfd);
    //TODO: app code
  } exit(0);}
