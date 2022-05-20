#include <stdio.h>
#include <stdlib.h>

void copy_string(char *dest, const char *src)
{ 
  for (;*src; dest++, src++)/*calculate both variables, but put as value only*/
    *dest=*src; /*the second. Smart!*/
  *dest=0;
}

  
int main(){
  char m[] = {"Hello"};
  char *p;
  char *ptr = "Hello";
  m[4] = 0;
  ptr[4] = 0;
  /*There will be the Segmentation Fault error cause we trying change String
literal that lying in unchaingable segment of memory e.d. segment of code*/
  p = malloc(6*sizeof(char));
  copy_string(p,m);
  printf("%c%c%c%c%c\n",*p, *(p+1), *(p+2), *(p+3), *(p+4));
  printf("size of array are: %ld. Size of pointer are: %ld\n",sizeof(m), sizeof(ptr));
  return 0;
}
