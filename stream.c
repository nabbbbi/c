#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static const char message[] = "query";
char buf[10];

int main()
{
  struct sockaddr_in server;
  struct sockaddr client;
  socklen_t addrlen;
  int ok,sock_server,sock_client, connected_sock;
  /*creating server*/
  sock_server = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_server < 0)
    {
      perror("socket");
      exit(1);
    }
  server.sin_family=AF_INET;
  server.sin_port=htons(1024);
  server.sin_addr.s_addr=htonl(INADDR_ANY);
  ok = bind(sock_server,(struct sockaddr*)&server,sizeof(server));
  if(ok < 0)
    {
      perror("bind");
      exit(1);
    }
  listen(sock_server, 16);
  addrlen = sizeof(client);
  memset(&client,0,addrlen);
    /*creating server is done. Now we about to create client*/
  sock_client = socket(AF_INET, SOCK_STREAM, 0); /*ip+port will be create automatically by OS*/
  if(sock_client < 0)
    {
      perror("client");
      exit(1);
    }
  ok = connect(sock_client,(struct sockaddr*)&server, sizeof(server));
  if (ok < 0)
    {
      perror("connect");
      exit(1);
    }
  /*client and server are ready. Now we may create connected socket*/
  connected_sock = accept(sock_server,&client,&addrlen);
  if (connected_sock < 1)
    {
      perror("accept");
      exit(1);
    }
  write(sock_client,message,sizeof(message)); /*write as a client*/
  write(sock_client,"\n",1);
  read(connected_sock,buf,sizeof(buf)); /*receive as a server*/
  printf("%s",buf);
  shutdown(connected_sock,SHUT_RDWR); /*close sd in both directions*/
  close(connected_sock);
  shutdown(sock_client,SHUT_WR); /*shut sd to send messages */
  close(sock_client);
  shutdown(sock_server,SHUT_RD); /*shut sd to read messages*/
  close(sock_server);
  return 0;
}
