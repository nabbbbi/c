#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,i;
  gid_t *p;
  n=getgroups(0,NULL);
  p=malloc(n*sizeof(gid_t));
  getgroups(n,p);
  printf("%d complementary groups of proccess",n);
  for (i=0; i< sizeof(p); i++)
    {
      printf("%d\n",p[i]);
    }
 return 0;
}
