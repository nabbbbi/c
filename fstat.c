#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char error [] = "Can't get stat of file";
static const char message [] = "Done";

/*struct stat {
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;
  blksize_t st_blksize;
  blkcnt_t st_blocks;
st_atime;
st_mtime;
st_ctime;
  };*/

struct stat sfile;

int main()
{
  int n,p;
  p =open("/home/pi/test/some1.txt",O_RDONLY);
  n =fstat(p,&sfile); /*works with symlink*/
  if(n<0) 
    {
      write(1,error,sizeof(error));
      write(n,"\n",1);
      return 1;
    }
  write(1,message,sizeof(message));
  write(n,"\n",1);
  printf("st_mode = %o\n", sfile.st_mode); /*It indicates the permissions on 
					     the file, tells the modes on a 
					     file. Following are the flags 
					     that should be defined for 
					     st_mode field:*/
  printf("st_dev = %ld\n", sfile.st_dev); /*It is the ID of device in which
					    we have our file residing 
					    currently*/
  printf("st_ino = %lo\n", sfile.st_ino); /*It is the inode number or the 
					    serial number of the file. As it 
					    is an index number so it should 
					    be unique for all 
					    files */
  printf("st_nlink = %o\n", sfile.st_nlink); /*This field tells the total 
					       number of hard links.*/
  printf("st_uid = %o\n", sfile.st_uid); /*This field indicates the user ID.*/
  printf("st_gid = %o\n", sfile.st_gid); /*This field indicates the group ID*/
  printf("st_rdev = %lo\n", sfile.st_rdev); /*This field describes that a 
					      particular file represents a 
					      particular device.*/
  printf("st_size = %lo\n", sfile.st_size); /*st_size is the size of the file 
					      in bytes.*/
  printf("st_blksize = %o\n", sfile.st_blksize); /*This field gives the 
						   preferred block size for 
						   I/O file system which may 
						   vary from file to file.*/
  printf("st_blocks = %lo\n", sfile.st_blocks); /*This field tells the total 
						  number of blocks in multiples
						  of 512 bytes.*/
  printf("st_atime = %lo\n", sfile.st_atime); /*It is the last time or the
						recent time at which the file
						was accessed.*/
  printf("st_mtime = %lo\n", sfile.st_mtime); /*It is the recent time at which
						the file was modified.*/
  printf("st_ctime = %lo\n", sfile.st_ctime); /*It is the recent time at which 
						the status or the permissions 
						of the file was changed.*/
  return 0;
}
