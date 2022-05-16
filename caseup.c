/* caseup.c */
#include <stdio.h>

char case_up (char c) {
  if (c >= 'a' && c <= 'z') /* is 'c' low register symbol ? */
    return c - ('a' - 'A'); /* if YES then make it high register!  */
  else /* 'a' - 'A' equal 20. subtraction of any low reg symbol 20 is high reg*/
    return c;
}
int main () {
  int n,c;
  printf("type character, beach!\n");
  n = scanf("%lc", &c); /*why 'lc' actually ? */
  if (n > 1) {
    printf("what the fuck man? Where 2 number?");
    return 1;
  }
  c = case_up(c); /*return value is absolutly nesessary if we want to work*/
  /*with internal variable from function */
  printf("Good boy! now take your result!\n%c\n see you!\n",c);
  return 0;
}
