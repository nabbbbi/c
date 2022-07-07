#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static const char error_ip2 [] = "Can't create ip2\n";
static const char error_ip3 [] = "Can't create ip3\n";
static const char error_port1 [] = "Can't create port1\n";
static const char error_port2 [] = "Can't create port2\n";
static const char error_port3 [] = "Can't create port3\n";

const char *serv_ip1 = "192.168.0.13";
const char *serv_ip2 = "192.168.0.14";
const int port1 = 7500;
const int port2 = 7501;
const int port3 = 7502;
char *message = "Hello";

void handler(int s)
{
  signal(SIGALRM, handler);
  int save;
  save = errno;
  printf("5 seconds are past\n");
  errno = save;
}

int main()
{
  char *s;
  int sockfd,res,ok;
  socklen_t inet1, inet2;
  struct sockaddr_in addr1, addr2,addr3;
  struct timeval tv;
  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sockfd < 0) /*socket file descriptor*/
    {
      s = strerror(errno);
      printf("%s\n",s);
      exit(1);
    }
  /*fill address structure of sender*/
  addr1.sin_family=AF_INET;
  ok =  addr1.sin_port=htons(port1);
  if (!ok)
    {
      write(1,error_port1,sizeof(error_port1) -1);
      return 1;
    } 
  addr1.sin_addr.s_addr = htonl(INADDR_ANY);
  /*end filling*/
  res = bind(sockfd,(struct sockaddr*)&addr1,sizeof(addr1));
  if (res == -1)
    {
      s = strerror(errno);
      printf("%s\n",s);
      exit(1);
    }
  /*fill address structure of sender*/
  addr2.sin_family=AF_INET;
  ok = addr2.sin_port=htons(port2);
  if (!ok)
    {
      write(1,error_port2,sizeof(error_port2) -1);
      return 1;
    }
  ok = addr2.sin_addr.s_addr = inet_addr(serv_ip1);
  if (!ok)
    {
      write(1,error_ip2,sizeof(error_ip2) -1);
      return 1;
    }
  /*end filling*/
  inet1 = sizeof(addr2); /*special constant that should be equal to send and 
			 reseive functions*/
  ok = sendto(sockfd,message,sizeof(message),0,
	 (struct sockaddr*)&addr2,inet1);
  printf("%d bytes are sent\n",ok);
  if (ok < 0)
    {
      perror("sendto");
      exit(1);
    }
  /*sendto function is ready*/

   /*fill address structure of receivier*/
  addr3.sin_family=AF_INET;
  ok = addr3.sin_port=htons(port3);
  if (!ok)
    {
      write(1,error_port3,sizeof(error_port3) -1);
      return 1;
    }
  ok =  addr3.sin_addr.s_addr = inet_addr(serv_ip2);
  if (!ok)
    {
      write(1,error_ip3,sizeof(error_ip3) -1);
      return 1;
    } 

  inet2 = sizeof(addr3);
  signal(SIGALRM, handler);
  tv.tv_sec = 3;
  tv.tv_usec = 500000;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
  alarm(5);
  pause();
  ok=recvfrom(sockfd, message, sizeof(message), 0,
	 (struct sockaddr*)&addr3, &inet2);
  if (ok < 0)
    {
      perror("recvfrom");
      exit(1);
    }
  /*receive function is ready*/
  printf("result should be zero if socket successfully binded.\nAnd result is '%d'\n",res);
  return 0;
}
