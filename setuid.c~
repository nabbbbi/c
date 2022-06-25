#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  int n;
  n = getuid();
  printf("uid is %d\n",n);
  n = geteuid();
  printf("euid is %d\n",n); /*effective uid means that was before setuid*/
  n = getgid();
  printf("gid is %d\n",n);
  n = getegid();
  printf("egid is %d\n",n);
  return 0;
}
