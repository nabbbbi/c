#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
static const char error [] = "Can't read";

/*void *mmap (void *start, int length, int protection, int flags, int fd, int offset); we can use mmap to see file in virtual space of process and word with
  file like space in RAM. offset and length choose place in file that we should work with*/ 

int main()
{
  int fd,pgs;
  char *p; /*for return value of mmap*/
  int size = 4096;
  pgs = getpagesize();
  size = ((size-1) / pgs + 1) * pgs; /*minimal values, above or equal init 
				       value and the same time divided size 
				       of page*/
  fd = open("/home/pi/test/some1.txt",O_RDWR);
  if(fd == -1)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  p = mmap(NULL,size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,0);
  if (p == MAP_FAILED) /*MAP_SHARED - changes in virtual space by process
			don't touch file. (alt MAP_PRIVATE). Start choose
position that start use new memory of file in virtural space of process, PROTECTION should be the same as rights while open function. if we choose MAP_ANUNYMOUS mmap just create new virtual space.
Return value of mmap is pointer to new virtual space by it immedietly change to *char. if error mmap return MAP_FAILED (-1) */
    if(p<0)
    {
      write(2,error,sizeof(error));
      return 2;
    }
  /*we can to p[n] byte of new memory any symbol*/
  printf("%d\n",p[100]); /*read p[n] byte fromm file*/
  /* p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0); alt for malloc. p will store addres of new virtual space that get from OS*/
  /*int munmap(void *start, int length); cancel mmap that we made*/
  close(fd);
  return 0;
}
