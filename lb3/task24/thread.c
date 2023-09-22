#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sched.h>
pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
void* thread1()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_1 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_1: %d\n", i);
}
}
void* thread2()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_2 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_2: %d\n", i);
}
}

void* thread3()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_3 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_3: %d\n", i);
}
}

void* thread4()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_4 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_4: %d\n", i);
}
}

void* thread5()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_5 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_5: %d\n", i);
}
}

void* thread6()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_6 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 100; i++)
{
printf("Thread_6: %d\n", i);
}
}

void* thread7()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_7 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_7: %d\n", i);
}
}

void* thread8()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_8 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_8: %d\n", i);
}
}

void* thread9()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_9 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_9: %d\n", i);
}
}

void* thread10()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_10 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_10: %d\n", i);
}
}

void* thread11()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_11 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_11: %d\n", i);
}
}

void* thread12()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_12 with thread id = %d and pid = %d is started\n", tid, pid);
for (i = 0; i < 10; i++)
{
printf("Thread_12: %d\n", i);
}
}

void main()
{
int policy;
struct sched_param param;
pthread_attr_t  attr_1, attr_2, attr_3, attr_4, attr_5, attr_6, attr_7, attr_8, attr_9, attr_10, attr_11, attr_12;
pthread_attr_t  attr[12] = {attr_1, attr_2, attr_3, attr_4, attr_5, attr_6, attr_7, attr_8, attr_9, attr_10, attr_11, attr_12};
for(int i = 0; i < 5; i++){
pthread_attr_init(&attr[i]);
pthread_attr_setschedpolicy(&attr[i], SCHED_FIFO);
param.sched_priority = 1;
pthread_attr_setschedparam(&attr[i], &param);
pthread_attr_setinheritsched (&attr[i], PTHREAD_EXPLICIT_SCHED); 
pthread_attr_getschedparam(&attr[i], &param);
pthread_attr_getschedpolicy(&attr[i], &policy);
printf("Thread #%d's priority = %d\n",i, param.sched_priority); 
}

//значения приоритетов лучше задавать извне – из командной строки или файла


//param.sched_priority = 30;
//pthread_attr_setschedparam(&attr_2, &param);
// Стратегия планирования и связанные с ней атрибуты должны быть взяты из описателя //атрибутов, на который указывает аргумент attr 

// Стратегия планирования и связанные с ней атрибуты должны быть унаследованы
// Установка атрибута наследования от родителя
//pthread_attr_setinheritsched (&attr_1,PTHREAD_INHERIT_SCHED)
// Установка статуса освобождения ресурсов
//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


switch (policy) {
case SCHED_FIFO:
printf ("policy SCHED_FIFO\n");
break;
case SCHED_RR:
printf ("policy SCHED_RR\n");
break;
case SCHED_OTHER:
printf ("policy SCHED_OTHER\n");
break;
case -1:
perror ("policy SCHED_GETSCHEDULER");
break;
default:
printf ("policy Неизвестная политика планирования\n");
}

pthread_create(&t1, &attr[0], thread1, NULL);
pthread_create(&t2, &attr[1], thread2, NULL);
pthread_create(&t3, &attr[2], thread3, NULL);
pthread_create(&t4, &attr[3], thread4, NULL);
pthread_create(&t5, &attr[4], thread5, NULL);
/*
pthread_create(&t6, &attr[5], thread6, NULL);
pthread_create(&t7, &attr[6], thread7, NULL);
pthread_create(&t8, &attr[7], thread8, NULL);
pthread_create(&t9, &attr[8], thread9, NULL);
pthread_create(&t10, &attr[9], thread10, NULL);
pthread_create(&t11, &attr[10], thread11, NULL);
pthread_create(&t12, &attr[11], thread12, NULL);*/
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
pthread_join(t4, NULL);
pthread_join(t5, NULL);
/*
pthread_join(t6, NULL);
pthread_join(t7, NULL);
pthread_join(t8, NULL);
pthread_join(t9, NULL);
pthread_join(t10, NULL);
pthread_join(t11, NULL);
pthread_join(t12, NULL);*/
pthread_attr_destroy(&attr[0]);
pthread_attr_destroy(&attr[1]);
pthread_attr_destroy(&attr[2]);
pthread_attr_destroy(&attr[3]);
pthread_attr_destroy(&attr[4]);
/*
pthread_attr_destroy(&attr[5]);
pthread_attr_destroy(&attr[6]);
pthread_attr_destroy(&attr[7]);
pthread_attr_destroy(&attr[8]);
pthread_attr_destroy(&attr[9]);
pthread_attr_destroy(&attr[10]);
pthread_attr_destroy(&attr[12]);*/
}
