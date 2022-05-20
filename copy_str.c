#include <stdio.h>
#include <stdlib.h>

void copy_string(char *dest, const char *src){
  int i;
  for (i=0; src[i]; i++)
    dest[i] = src[i];
  dest[i]='\0';
}

int main(){
  char m[] = {'H','e','l','l','o','\0'};
  char *p;
  p = malloc(6*sizeof(char));
  copy_string(p,m);
  printf("%c%c%c%c%c\n",*p, *(p+1), *(p+2), *(p+3), *(p+4));
  return 0;
}
