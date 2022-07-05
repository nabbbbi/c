#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

static const char error [] = "Can't create socket\n";
static const char error_bind [] = "Can't bind socket and ip address\n";
const char *serv_ip = "192.168.0.13";
const int Port = 7500;

int main()
{
  int sockfd,res;
  struct sockaddr_in addr; /*structure to create ip address + port*/
  sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); /*AF_UNIX is alternative.
						       SOCKDGRAM. IPPROTO_UDP.
						      But usually 3rd argument
						      is 0. because previous
						      arguments already define
						      3rd argument*/
  if (sockfd < 0)
    {
      write(1,error,sizeof(error) -1);
      exit(1);
    }
  addr.sin_family=AF_INET; /*address family*/
  addr.sin_port=htons(Port); /*htons convert digits to netdigits(big endian)*/
#if 0 /*mostly used for adding receivient ip address not sender*/
  int ok;
  static const char error_aton [] = "Can't generate ip address\n";
  ok = inet_aton(serv_ip,&addr.sin_addr); /*does the same as progenitor but
					   ip address*/
  /*unsigned int htonl(unsigned int hostlong);
   unsigned short int htons (unsigned short int hostshort);
  unsigned int htonl(unsigned int netlong);
  unsigned short int htohs(unsigned short int netshort);*/
  if (ok < 1)
    {
      write(1,error_aton,sizeof(error_aton) - 1);
      return 2;
    }
  #endif
  #if 1
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  #endif
  
  res = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr)); /*bind ip+port with
							    socket.
							   Here we convert
							   type of second
							   argument cause we
							   work with structure
							   as 'sockaddr_in' 
							   for AF_INET. But
							   bind take argument
							   only as socketaddr
							   for AF_UNIX*/
  if (res == -1)
    {
      write(1,error_bind,sizeof(error_bind) -1);
      return 3;
    }
  printf("result should be zero if socket successfully binded.\nAnd result is '%d'\n",res);
  return 0;
}
