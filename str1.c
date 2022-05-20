#include <stdio.h>

int string_length(const char *str){
  int i;
  for (i=0;str[i]; i++)
    {}
  return i;
}

int main() {
  int n;
  char m[] = {'H', 'e', 'l', 'l','o','\0'}; 
  n = string_length(m); /*give to function adress of the first element*/
  printf("letters on Hello are : %d\n",n); 
  return 0;
}
  
