#ifndef MOVEMODE_N_SENTRY
#define MOVEMODE_N_SENTRY

int open(const char *name, int mode);
int open(const char *name, int mode, int perms);
int umask(int mask);
int read(int fd, void *mem, int len);
int write(int fd, const void *data, int len);
long lseek(int fd, long offset, int whence);
int close(int fd);

#endif
