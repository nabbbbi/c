#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

struct rlimit *rlim;
static const char error [] = "can't do this";

int main()
{
  int n;
  n=setrlimit(RLIMIT_AS, rlim);
  if(n == -1)
    {
      write(1,error,sizeof(error));
      return 0;
    }
  printf("%d\n",n);
  return 0;
}
