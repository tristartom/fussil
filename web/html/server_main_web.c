#include "csapp.h"

char* resp_404 = "HTTP/1.1 404\r\n\r\nContent-Length: 0\r\n";
char* resp_button = "HTTP/1.1 200 OK\r\n"
      "Content-Length: 115\r\n"
      "Content-Type: text/html; charset=utf-8\r\n"
      "\r\n"
      "<button type=\"button\">OrangeButton</button>\r\n"
      "<img src=\"127.0.0.1:2009\" alt=\"broken image\" width=\"10\" height=\"10\"/>";

void handle_client_web(int connfd){
  char buf2[1000];
  while (read(connfd, buf2, 1000) > 0){
    printf("%s", buf2);
//https://stackoverflow.com/questions/33784127/minimal-http-server-reply
//  write(connfd, resp_404, 200);
    write(connfd, resp_button, 500);
  } close(connfd);}

int main(int argc, char **argv) {
  int port = atoi(argv[1]), listenfd, connfd;
  struct sockaddr_in clientaddr;
  socklen_t clientlen = sizeof(clientaddr);
  listenfd = open_listenfd(port);
  while (1) {
    connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
    printf("Socket connected: %d\n", connfd);
    //TODO: app code: multi-process echo server 
    if(fork() == 0){
      handle_client_web(connfd); exit(0);
  }}}
