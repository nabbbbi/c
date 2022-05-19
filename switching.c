/* switching */
#include <stdio.h>

int main () {
  int t,n;
  printf("type number, bitch!\n");
  n = scanf("%d",&t);
  if (n != 1 || t > 5) {
    printf("Just error! Whatever, asshole.\n");
    return 1;
  }
  switch(t+1) {
  case 1 :
    printf("First!\n");
    break;
  case 2:
    printf("Second!\n");
    break;
  case 3:
    printf("Third!\n");
    break;
  case 4:
    printf("Forth!\n");
    break;
  case 5:
    printf("Fifth!\n");
    break;
  default:
    printf("More!\n");
  }
  return 0;
}
  
