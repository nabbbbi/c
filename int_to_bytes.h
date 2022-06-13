#ifndef NEWMODE_N_SENTRY
#define NEWMODE_N_SENTRY
union split
{
  int integer;
  unsigned char bytes[sizeof(char)];
};

void int_byte(int n);

#endif
