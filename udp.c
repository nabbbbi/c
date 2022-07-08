#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void handler(int s)
{
  int save;
  save = errno;
  signal(SIGALRM, handler);
  printf("5 seconds are past\n");
  errno = save;
}

int main()
{
  char data_sent[5000];
  char data_received[5000];
  int sockfd, bytes_sent, bytes_received,ok;
  socklen_t addrlen;
  struct sockaddr_in to, for_sock;
  struct sockaddr from;
  struct timeval tv;
  const int sock_port = 1024;
  const int to_port = 1025;
  memset(data_sent, 5, sizeof(data_sent));

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) /*socket file descriptor*/
    {
      perror("sockfd");
      exit(1);
    }
  for_sock.sin_family=AF_INET;
  for_sock.sin_port=htons(sock_port);
  for_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  ok = bind(sockfd,(struct sockaddr*)&for_sock,sizeof(for_sock));
  if (ok < 0)
    {
      perror("bind");
      exit(1);
    }
  memset(&to, 0, sizeof(to)); /*initialize structure*/
  /*  to.sin_family = AF_INET;
  to.sin_addr.s_addr = htonl(*eth0);
  to.sin_port = htons(to_port);*/
  bytes_sent = sendto(sockfd, data_sent, sizeof(data_sent), 0, (struct sockaddr*)&for_sock, sizeof(for_sock));
  if (bytes_sent < 1)
    {
      perror("sendto");
      exit(1);
    }
  alarm(5);
  signal(SIGALRM, handler);
  tv.tv_sec = 3;
  tv.tv_usec = 500000;
  setsockopt(sockfd,SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
  addrlen = sizeof(from);
  pause();
  bytes_received = recvfrom(sockfd, data_received, sizeof(data_received), 0, &from, &addrlen);
  close(sockfd);
  if (bytes_received < 0)
    {
      perror("recvfrom");
      exit(1);
    }
  else
    printf("Success. Well done! message received! It's %d chars\n",data_received[100]);
  return 0;
}
