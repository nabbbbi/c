#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

char *message = "hello";
char buf[10];

int main()
{
  socklen_t len;
  int ok_7, sockfd;
  struct sockaddr_in addr;
  sockfd = socket(AF_INET,SOCK_DGRAM,0);
  if(sockfd == -1)
    {
      perror("socket");
      return 1;
    }
  /* forming address */
  addr.sin_family = AF_INET;
  addr.sin_port = htons(1024);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  /* forming addres is end */
  ok_7 = bind(sockfd,(struct sockaddr*)&addr, sizeof(addr));
  if (ok_7 ==- 
      perror("bind");
      return 1;
    }
  ok_7 = sendto(sockfd, message, sizeof(message),0,
		(struct sockaddr*)&addr,sizeof(addr));
  if (ok_7 == 1)
    {
      perror("sendto");
      return 1;
    }
  len = sizeof(addr);
  /* we do not give address to recvfrom address. recvfrom get it yourself */
  ok_7 = recvfrom(sockfd, buf, sizeof(buf),0,
		  (struct sockaddr*)&addr,&len); /*len is variable*/
  if(ok_7 == 1)
    {
      perror("recvfrom");
      return 1;
    }
  printf("%s\n",buf);
  return 0;
}
