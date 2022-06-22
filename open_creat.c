#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static const char error_arg [] = "didn't type arguments. please type 2 arguments";
static const char error_file [] = "cant't open file";

int main(int argc, char **argv)
{
  int n=0,m,mask;
  mask=umask(400); /*subtraction rights from rights that creat that process*/
  if(argc<3)
    {
      write(1,error_arg,sizeof(error_arg));
      write(n,"\n",1);
      return 1;
    }
  n = open(argv[1], O_RDWR | O_CREAT,0600);
  if(n<0)
    {
      write(1,error_file,sizeof(error_file));
      write(n,"\n",1);
      return 1;
    }
  m = write(n,argv[2],sizeof(argv[2]));
  if(m<0)
    {
      write(2,error_file,sizeof(error_file));
      write(n,"\n",1);
      return 2;
    }
  printf("%d %d\n",m,mask);
  write(n,"\n",1);
  close(n);
  return 0;
}
