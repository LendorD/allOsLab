#include <stdio.h>
#include <unistd.h>
void main() {
   int pid,ppid;
   pid=getpid();
   ppid=getppid();
   printf("SON_3 PARAMS:  pid=%i  ppid=%i\nson3terminated–ZOMBIE\n",pid,ppid);
   ppid=getppid();
   printf("SON_3 PARAMS:  pid=%i  ppid=%i\n",pid,ppid);
}
