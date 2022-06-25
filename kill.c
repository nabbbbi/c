#include <sys/types.h>
#include <signal.h>

int main()
{
  kill(3937,SIGTERM); /*if pid = -1, kill of processes exclude this and init
			any -[n] means kill group processes with n pid, if 0 
			it means kill all proccesses from my group exclude me*/
  return 0;
}
