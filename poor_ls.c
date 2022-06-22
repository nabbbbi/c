#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char **argv)
{
  DIR *dir; /*this will be address of directory. type of catalog*/
  struct dirent *dent; /*return values of fucntion*/
  const char *name = "."; /*name of the directory*/
  if (argc>1) /*if we put any directory in cmdline*/
	   name = argv[1];
  dir = opendir(name);
  if(!dir)
    {
      perror(name);
      return 1;
    }
  while((dent = readdir(dir)) != NULL) /*readdir will read records from 
directory until NULL*/
    {
      printf("%s\n", dent->d_name);
    }
  closedir(dir);
  return 0;
}
