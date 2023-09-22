#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
pthread_t t1, t2;


void handler()
{
    puts("Signal's received");
    pthread_exit(NULL);
}


void* thread1()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();
printf("Thread_1 with thread id = %d and pid = %d is started\n", tid, pid);
int n=3; //можно установить любым

for (int i = 0; i < n; i++)
{
count += 1;
printf("Thread_1: step %d \n", count);
sleep(5);
pthread_kill(t2, SIGUSR1);
// отправка обычных сигналов из первой нити во вторую
/*pthread_kill(t2, SIGUSR2);
pthread_kill(t2, SIGUSR1);

pthread_kill(t2, SIGRTMIN+3);// отправка сигналов реального времени
pthread_kill(t2, SIGRTMIN+1);
pthread_kill(t2, SIGRTMIN+5);
pthread_kill(t2, SIGRTMIN+1); */
}
}
void* thread2()
{
int i, count = 0;
int tid, pid;
tid = syscall(SYS_gettid);
pid = getpid();

printf("Thread_2 with thread id = %d and pid = %d is started\n", tid, pid);
int m=10; //можно подобрать на свое усмотрение, чтобы все сигналы
//успевали доставиться
signal(SIGUSR1, handler);
for (int i = 0; i < m; i++)
{
count += 1;
sleep(1);
printf("Thread_2: step %d\n", count);

}
}
void main()
{
pthread_create(&t1, NULL, thread1, NULL);
pthread_create(&t2, NULL, thread2, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
}
