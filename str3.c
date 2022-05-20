#include <stdio.h>

int string_length(const char *str){
  int i;
  i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}

int main() {
  int n;
  char m[] = {'H', 'e', 'l', 'l','o','\0'}; 
  n = string_length(m); /*give to function adress of the first element*/
  printf("letters on Hello are : %d\n",n); 
  return 0;
}
  
