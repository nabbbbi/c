#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int create_netsocket_dgram(const int port)
{
  int ok_7, sockfd;
  struct sockaddr_in addr;
  sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
  if(sockfd == -1)
    {
      perror("socket");
      return 1;
    }
  /* forming address */
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  /* forming addres is end */
  ok_7 = bind(sockfd,(struct sockaddr*)&addr, sizeof(addr));
  if (ok_7 == -1)
    {
      perror("bind");
      return 1;
    }
  return sockfd;
}
