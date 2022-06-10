#include <stdio.h>
#include <stdlib.h>

union split_int {
  int integer;
  unsigned char bytes[sizeof(int)]; /*both fields has same address.
				      We put value in first field and work 
				      with that value via second fields 
				      without changing it*/
};

int main()
{
  int i;
  union split_int si; 
  printf("Type integer number: ");
  scanf("%d",&si.integer);
  for (i=0; i< sizeof(int); i++)
    printf("byte #%d is %02x\n", i, si.bytes[i]);
  return 0;
}
