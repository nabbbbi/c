#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int wr, status;
  wr = wait(&status); /*function to kill zombie process. return killed process
			if no zombie proccess return -1*/
  if (wr == -1)
    {
      printf("No child proccesses detected\n");
    }
  else
    {
      printf("Proccess with pid %d is finished\n",wr);
      if(WIFEXITED(status)) /*macros means process finished with standart way*/
	{
	  printf("is has exited with code = %d\n",WEXITSTATUS(status)/*if it was
								       with 
standart way then what finishing code*/);
	}
      else
	{
	  printf("it was killed by signal %d.\n",WTERMSIG(status)/*if process was finished with signal then what code of signal*/);
	}
      
    }
  return 0;
}
