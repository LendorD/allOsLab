#include <stdio.h>
#include "unistd.h"
int main() {
   printf("SONPARAMS:  pid=%i  ppid=%i\n",getpid(),getppid());
   int n = nice(1000);
   if(n == -1)perror("NICE");
   else
       printf ("Nice value = %d\n", nice);
   return 0;
}
