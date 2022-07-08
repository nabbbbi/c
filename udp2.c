#include <sys/socket.h>
int main()
{
  int sendto(int socket, char *buf, int buflen, int flags,
	     struct sockaddr *addr, int addrlen);
  int recvfrom(int socket, char *buf, int buflen, int flags,
	       struct sockaddr *addr, int *addrlen);
  int bytes_sent;
  int bytes_received;
  char data_sent[256];
  char data_received[256];
  struct sockaddr_in to;
  struct sockaddr from;
  int addrlen;
  int s;
  ⋮
    memset(&to, 0, sizeof(to));
    to.sin_family = AF_INET;
    to.sin_addr   = inet_addr(“129.5.24.1”);
    to.sin_port   = htons(1024);
    ⋮
      bytes_sent = sendto(s, data_sent, sizeof(data_sent), 0,
			  (struct sockaddr*)&to, sizeof(to));
      ⋮
	addrlen = sizeof(from); /* must be initialized */
	bytes_received = recvfrom(s, data_received,
				  sizeof(data_received), 0, &from, &addrlen)
