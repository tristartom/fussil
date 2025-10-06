#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  struct in_addr ip;
  ip.s_addr = 127;
  //ip.s_addr = 257;
  //ip.s_addr = 1025;
  //inet_aton("1.4.0.0", &ip);
  printf("%ud\t%s\n",ip.s_addr, inet_ntoa(ip));
}
