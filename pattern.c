#include <stdio.h>

int match (const char *pat, const char *str)
{
  int i;
  for (;; str++, pat++)
    {
      switch(*pat)
	{
	case 0;
	return *str == 0;
	case '?':
	  if (!*str)
	    return 0;
	  break;
	case '*':
	...
	default:
	if(*str != *pat)
	  return 0;
	}
    }
}
