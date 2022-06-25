#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t child_ready;

void usr1hdl(int n)
{
  child_ready = 1;
}

int main()
{
  int pid;
  sigset_t mask_usr1, mask_empty;
  sigemptyset(&mask_usr1); /* multiplicity of 1 element (SIGUSR1)*/
  sigaddset(&mask_usr1, SIGUSR1); /*add signal to the list*/
  sigemptyset(&mask_empty); /*multiplicity mask_empty is empty now*/
  /* preparing to main proccess */
  child_ready = 0;
  /*int sigfillset(sigset_t *set); fill list with existing signals *f
    /*int sigdelset(sigset_t *set, int signum); delet from list choosen 
    signal*/
  /*int sigismember(const sigset_t *set, int signum); tells include list 
    this signal or not*/
  sigprocmask(SIG_SETMASK, &mask_usr1, NULL); /*SIG_SETMASK block all signal
					       exclude signals in 2nd 
					       parameters*/
  signal(SIGUSR1, usr1hdl); /*signal function will set signal in 1st parameter
			     by values or function that present if 2nd 
			     parameter*/
  if (pid == 0)
    {
      /*child proccess*/
      /*prepating*/
  kill(getppid(),SIGUSR1); /*sent signal to parent proccess(about 
			     child_ready var is 1 now)*/
  exit(0);
    }
  /* continuing parent proccess */
  while(!child_ready) /*while*/
    {
      sigsuspend(&mask_empty); /*this cmd will block all signals exists*/
    }
  /*child is ready now*/
  /*programm begin with both proccesses*/
  return 0;
}
