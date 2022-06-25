#include <unistd.h>
#include <signal.h>
#include <errno.h>

volatile static sig_atomic_t n = 0; /* special variable that told OS this var
				       must be proccessed emmediately. and also
				       its not suspended variable */
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
  alarm(1); /* set time until program wiil receive signal SIGALRM that kill
	     if don't handle it*/
  signal(SIGINT,handler); /*function here, but if while cycle because handler
			   work only when proccess will receive signal until
			  then it will wait*/
  while(n<25)
    {
      pause(); /* block program until proccess will receive signal*/
    } /* when n will 25 programm will end. change n can only handler*/
  return 0;
}
