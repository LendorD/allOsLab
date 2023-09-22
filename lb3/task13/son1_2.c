#include <signal.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void SIGUSR1_handler(int sig_no)
{
   time_t st_t;
   st_t = time(NULL);
   printf("son1 (sleeping) received the signal %d at time %s\n",sig_no, ctime(&st_t));
   exit(0);
}
int main() {
   signal(SIGUSR1, SIGUSR1_handler);
   printf("son1\n");
   sleep(3);
   return 0;
}
