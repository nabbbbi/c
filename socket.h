#ifndef NEWMOD_H_SENTRY
#define NEWMOD_H_SENTRY

/*udp*/
int sendto(int s, const void *buf, int len, int flags, const struct sockaddr *to, socklen_t tolen);
int recvfrom(int s, void *buf, int len, int flags, struct sockaddr *from, socklen_t *fromlen);

int bind(int sockfd, struct sockaddr *addr, int addrlen);
int socket(int family, int type, int protocol);

unsigned int htonl(unsigned int hostlong);
unsigned short int htons(unsigned short int hostshort);
unsigned int ntohl(unsigned int netlong);
unsigned short int ntohs(unsigned short int netshort);

int inet_aton(const char *cp, struct in_addr *inp);
unsigned int inet_addr(const char *cp);

#endif
