#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f;
  f = fopen("file.txt", "r");
  if (!f)
    {
      perror("file.txt");
      exit(1);
    }
  int fclose(FILE *f);
  return 0;
}
