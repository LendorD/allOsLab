#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main ()
{
    struct sched_param shdprm; // значения параметров планирования
    int ppid, status;
    int pid[6];//pid [1 - 5] для потомков, 0й - родитель
    int n = 50;//одинаковый приоритет

    pid[0] = getpid();
    ppid = getppid();
    printf("FATHER PARAMS: pid=%i ppid=%i\n", pid[0],ppid);
    shdprm.sched_priority = n;
    char perror_shed [] = "SCHED_SETSCHEDULER_ ";
    char son_name [] = "son0";
    int arr [3] = {SCHED_FIFO, SCHED_RR};
    if (sched_setscheduler (0, SCHED_FIFO, &shdprm) == -1)
    {
        perror (perror_shed);
    }
    for(int i = 1; i < 6; i++) {
        if ((pid[i] = fork()) == 0) {
            shdprm.sched_priority = n;
            son_name[3] = i + '0';
            perror_shed[19] = i + '0';
            if (sched_setscheduler(pid[i], arr[i % 2], &shdprm) == -1)
                perror(perror_shed);
            execl(son_name, son_name, NULL);
        }
    }

    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    return 0;
}
