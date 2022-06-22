#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

static const char error [] = "can't open device file";
static const char message [] = "success";

struct cdrom_ti cti;

int main()
{
  int n,m;
  n = open("/dev/cdrom",O_RDONLY | O_NONBLOCK);
  if(n<0)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  cti.cdti_trk0=2;
  cti.cdti_ind0=0;
  cti.cdti_trk1=2;
  cti.cdti_ind1=0;
  ioctl(n, CDROMPLAYTRAKIND, &cti);
  
  m = write(n,message,sizeof(message));
  if(m<0)
    {
      write(1,error,sizeof(error));
      return 2;
    }
  printf("%d\n",m);
  write(n,"\n",1);
  close(n);
  return 0;
}
