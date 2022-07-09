enum {listen_queue_len = 16};
int ls, ok;
struct sockaddr_in addr;
ls = socket(AF_INET, SOCK_STREAM, 0);
if (ls == -1)
  {
    perror("socket");
    exit(1);
  }
addr.sin_family = AF_INET;
addr.sin_port = htons(port);
addr.sin_addr.s_addr=htonl(INADDR_ANY);
ok = bind(ls, (struct sockaddr*)&addr, sizeof(addr));
if (ok < 1)
  {
    perror("bind");
    exit(1);
  }
listen(ls, listen_queue_len);
for(;;)
  {
    int cls,pid;
    socklen_t slen = sizeof(addr);
    cls = accept(ls,&addr,slen);
    pid = fork();
    if (pid == 0)
      {
	close(ls);
	/* now we work with client through socket cls. Client come from address
that store in addr */
	exit(0);
      }
    /*parent proccess*/
    close(cls);
    /*check zombie proccesses*/
    do
      {
	pid = wait4(-1, NULL, WNOHANG,NULL);
      } while (pid > 0);
    return 0;
  }
