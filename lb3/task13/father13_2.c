#include <signal.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include <stdio.h>
int main() {
   int pid[2];
   char * son[2] = {"son1_2", "son2_2"};
   for(int i = 0; i < 2; i++) {
       if((pid[i] = fork()) == 0) {
           execl(son[i], son[i], NULL);
       }
   }
   printf("father\n");
   system("ps");
   for(int i = 0;i < 2; i++) {
       kill(pid[i], SIGUSR1);
   }
   time_t st_t;
   st_t = time(NULL);
   printf("signals sended at time %s\n", ctime(&st_t));
   sleep(2);
   system("ps");
}
