#include <unistd.h>
#include <stdio.h>

int main()
{
  #if 0
  char *cmdline [] = {"ls","-l","-a","/var",NULL};
  execvp("ls",cmdline);
  perror("ls");
  fflush(stderr); /*pop data from buffer*/
  _exit(1);
  #endif
  #if 1
  execlp("ls","ls","-l", "-a", "/var", NULL);
  perror("ls");
  fflush(stderr);
  _exit(1);
  #endif
  return 0;
}
