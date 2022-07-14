#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int create_netsocket_dgram(const int port, const char *address)
{
  int sockfd, ok_7, option;
  struct sockaddr_in addr;
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1)
    {
      perror("socket");
      return sockfd;
    }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if(!address)
    {
      addr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
  else
    {
      addr.sin_addr.s_addr = inet_addr(address);
      if (!addr.sin_addr.s_addr)
	{
	  perror("inet_addr");
	  return ok_7;
	}
    }
  option = 1;
  ok_7 = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
		   &option, sizeof(option));
  if(ok_7 == -1)
    {
      perror("setsocket");
      return ok_7;
    }
  ok_7 = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
  if(ok_7 == -1)
    {
      perror("bind");
      return ok_7;
    }
  return sockfd;
}
