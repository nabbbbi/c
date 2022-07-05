#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

static const char error [] = "Can't create socket\n";
static const char error_bind [] = "Can't bind socket and ip address\n";
static const char error_send [] = "can't send. sorry\n";
const char *serv_ip = "192.168.0.13";
const int port1 = 7500;
const int port2 = 7501;
const static char message [] = "this is datagram\n";

int main()
{
  int sockfd,res,d;
  struct sockaddr_in addr;
  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_TCP);
  if (sockfd < 0)
    {
      write(1,error,sizeof(error) -1);
      exit(1);
    }
  /*begin filling net address*/
  addr.sin_family=AF_INET;
  addr.sin_port=htons(port1);
  addr.sin_addr.s_addr = htonl(INADDR_ANY); /*any available addr on this host*/
  /*end filling net address*/

  res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
  if (res < 0)
    {
      write(1,error_bind,sizeof(error_bind) -1);
      return 3;
    }
  d = sendto(sockfd,message, sizeof(message) - 1, 0, (struct sockaddr*)&addr,
	     sizeof(addr)); /*send datagram to address in sockaddr*/
  if (d < 0)
    {
      write(1,error_send,sizeof(error_send));
      return 4;
    }
  printf("result should be zero if socket successfully binded.\nAnd result is '%d'\n",res);
  return 0;
}
