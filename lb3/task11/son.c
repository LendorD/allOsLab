#include <stdio.h>
#include "unistd.h"
int main() {
   printf("SONPARAMS:  pid=%i  ppid=%i\n",getpid(),getppid());
   return 0;
}
