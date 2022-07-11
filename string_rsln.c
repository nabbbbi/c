/*this function returns length of string*/
int string_len_rsln(char *str)
{
  int n;
  char *c;
  c = str;
  while(*str)
    {
      str++;
      n++;
    }
  return str - c;
}

/*this function copy string from buffer to address with char type*/
void copy_string_rsln(char *dest, const char *src)
{ 
  while(*src) 
    { 
      *dest++=*src++; 
    } 
  *dest=0; 
}

