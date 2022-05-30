#include <stdio.h>

void string51(FILE *f1, FILE *f2)
{
  char buf[51];
  while (fgets(buf, sizeof(buf), f1))
    {
      int i;
      int nlpos = -1;
      for (i=0; i < sizeof(buf) && buf[i]; i++)
	if (buf[i] == '\n')
	  {
	    nlpos = i;
	    break;
	  }
      if (nlpos == -1) /*buf was't enough */
	{
	  int c;
	  fputc('\n', f2); /*print empty line cause buf was't enough*/
	  while ((c = fgetc(f1)) != EOF) /*if it's last line cycle will end
immediatly*/
	    if (c == '\n') /*not last line but was't enough for buf*/
	      break; /*this breaks EOF cycle*/
	}
      else
	{
	  buf[nlpos]='\0';
	  fprintf(f2,"[%s]\n",buf);
	}
    }
}

int main (int argc, char **argv)
{
  FILE *f1, *f2;
  if (argc < 3)
    {
      fprintf(stderr,"too few arguments");
      return 1;
    }
  f1 = fopen(argv[1], "r");
  if (!f1)
    {
      perror(argv[1]);
      return 2;
    }
  f2 = fopen(argv[2], "w");
  if (!f2)
    {
      perror(argv[2]);
      return 3;
    }
  string51(f1, f2);
  return 0;
}
