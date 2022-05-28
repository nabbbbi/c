#include <stdio.h>

void intfilesum(FILE *f, int *sum, int *count)
{
  int n;
  *sum = 0;
  *count = 0;
  while (fscanf(f,"%d",&n) == 1)
    {
      *sum+=n;
      (*count)++;
    }
}
int main(int argc, char **argv)
{
  FILE *f;
  int s,c;
  if (argc <2)
    {
      fprintf(stderr, "Too few arguments\n");
      return 1;
    }
  f = fopen(argv[1], "r");
  if (!f)
    {
      perror(argv[1]);
      return 2;
    }
  intfilesum(f,&s, &c); /*This has to be address draw from variable not a pointer*/
  printf("%d %d\n",s, c);
  fclose(f);
  return 0;
}
