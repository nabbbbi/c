#include <stdio.h>
#include <math.h>

int main()
{
  FILE *f;
  int i;
  f = fopen("file2.txt", "w");
  if (!f)
    {
      perror("file2.txt");
      return 1;
    }
  for (i=0; i<360; i++)
    {
      double grads, c, s;
      grads = ((double)i*M_PI/180);
      c = cos(grads);
      s = sin(grads);
      fprintf(f,"%lf %lf\n", c, s);
    }
  fclose(f);
  return 0;
}
      
