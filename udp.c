#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>

static const char error [] = "Can't create socket\n";
static const char error_bind [] = "Can't bind socket and ip address\n";
static const char error_send [] = "Can't send datagramm\n";
static const char error_rec [] = "Can't receive datagramm\n";
const char *serv_ip1 = "192.168.0.13";
const char *serv_ip2 = "192.168.0.14";
const int port1 = 7500;
const int port2 = 7501;
char *message = "Hello";

void handler(int s)
{}

int main()
{
  int sockfd,res,ok;
  socklen_t inet1, inet2;
  struct sockaddr_in addr1, addr2,addr3; 
  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sockfd < 0) /*socket file descriptor*/
    {
      write(1,error,sizeof(error) -1);
      exit(1);
    }
  /*fill address structure of sender*/
  addr1.sin_family=AF_INET;
  addr1.sin_port=htons(port1);
  addr1.sin_addr.s_addr = htonl(INADDR_ANY);
  /*end filling*/
  res = bind(sockfd,(struct sockaddr*)&addr1,sizeof(addr1));
  if (res == -1)
    {
      write(1,error_bind,sizeof(error_bind) -1);
      return 3;
    }
  /*fill address structure of sender*/
  addr2.sin_family=AF_INET;
  addr2.sin_port=htons(port2);
  addr2.sin_addr.s_addr = inet_addr(serv_ip1);
  if(!addr2.sin_addr.s_addr)
    {
      write(1,error,sizeof(error));
      return 5;
    }
  /*end filling*/
  inet1 = sizeof(addr2); /*special constant that should be equal to send and 
			 reseive functions*/
  ok=sendto(sockfd,message,sizeof(message),0,
	 (struct sockaddr*)&addr2,inet1);
  if (ok < 0)
    {
      write(1,error_send,sizeof(error_send) -1);
      return 4;
    }
  /*sendto function is ready*/

   /*fill address structure of receivier*/
  addr3.sin_family=AF_INET;
  addr3.sin_port=htons(port2);
  addr3.sin_addr.s_addr = inet_addr(serv_ip2);
  if(!addr3.sin_addr.s_addr)
    {
      write(1,error,sizeof(error));
      return 6;
    }
  /*end filling*/
  inet2 = sizeof(addr3);
  signal(SIGALRM, handler);
  alarm(5);
  ok=recvfrom(sockfd,message,sizeof(message),0,
	 (struct sockaddr*)&addr3,&inet2);
  if (ok < 0)
    {
      write(1,error_rec,sizeof(error_rec) -1);
      return 4;
    }
  /*receive function is ready*/
  
  printf("result should be zero if socket successfully binded.\nAnd result is '%d'\n",res);
  return 0;
}
sdffdsf
