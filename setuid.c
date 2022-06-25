#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  int n;
  n = getuid(); 
  printf("uid is %d\n",n);
  setuid(n); /*cat set "real", "effective" and "saved" rights if process has 
	      sudo privillegies*/
  n = geteuid();
  printf("euid is %d\n",n); /*effective uid means that was before setuid*/
  setgid(n); /*cat set "real", "effective" and "saved" rights if process has 
	      sudo privillegies*/
  n = getgid();
  printf("gid is %d\n",n);
  seteuid(n); /*cat set only "effective" identificator*/
  n = getegid(); 
  printf("egid is %d\n",n);
  setegid(n); /*cat set only "effective" identificator*/
  return 0;
}
