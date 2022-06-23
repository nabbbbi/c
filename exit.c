#include <stdio.h>
#include <unistd.h>

int main()
{
  #if 0
  printf("hello world!\n");
  fork(); /*in terminal will print one single time. On other hand on cat or
	    >> will print two times. because when proccess seee return 0(lib 
	    exit) it pop all buffers that he have. and parent proccess do that
	    to*/
  return 0; 
  #endif

  #if 0
  printf("hello, world");
  _exit(0); /*Wont print anything cause \n is not present*/
  #endif

  #if 1
  printf("hello, world\n");
  _exit(0); /*in terminal will print but on cat or >> wont work cause
	     terminal if see \n its pop buffer*/
  #endif
}
