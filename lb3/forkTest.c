#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
void main(int argc, char* argv[])
 {
 int m, n, pid;
 m=5000;
 pid = fork();
 if(pid == -1)
 {
	perror("fork error");
	exit(1);
 }
 printf("pid=%i\n",pid);
 while(1){
 if(pid != 0)
 {
	int j;
	sleep(1);
	 m-=1;
	printf("родитель: %i\n\n",m);
 } 
 else
 {

	 sleep(1);
	  m+=1;
	printf("потомок: %d\n\n",m);

 }
 }
 printf("Программа завершена\n");
 exit(1);
}
