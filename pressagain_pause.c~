#include <unistd.h>
#include <signal.h>
#include <errno.h>

volatile static sig_atomic_t n = 0; /* special variable that told OS this var
				       must be proccessed emmediately. and its
				       not suspended variable */
const char message [] = "Press it againt, I like it\n";

void handler(int s)
{
  int  save_errno = errno; /* save errno for write sys cal*/
  signal(SIGINT, handler); /*we do it because the next signal may not do job 
			     it time. and we reinstall handler as first 
			     command for next signal. if next signal don't 
			     come in time it will receive default handler*/
  /*this handler show what function would work if any signal will be received*/
  n++;
  write(1,message,sizeof(message)-1);
  errno=save_errno;
}

int main()
{
  signal(SIGINT,handler);
  while(n<25)
    {
      sleep(1); /*wait 1 second in order to CPU not stress too much*/
    }
  return 0;
}
