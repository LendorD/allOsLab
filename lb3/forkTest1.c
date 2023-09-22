#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
void main(int argc, char* argv[])
 {
 int m, n, pid;
 m=0;
 pid = fork();
 
 if(pid == -1)
 {
        perror("fork error");
        exit(1);
 }
 printf("pid=%i\n",pid);
 if(pid != 0)
 {
          m--;

        printf("родитель: %i\n\n",m);
 }
 else
 {
      
        m++;
        printf("потомок: %d\n\n",m);
 }
 printf("Программа завершена\n");
 exit(1);
}

