#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int COUNT = 5;

pthread_t t1, t2;

void handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Caught SIGUSR1 %d in Thread 2\n", sig);
        signal(sig, handler);
    } else if (sig == SIGUSR2) {
        printf("Caught SIGUSR2 %d in Thread 2\n", sig);
        signal(sig, handler);
    } else if (sig == SIGINT) {
        printf("Caught SIGINT %d in Thread 2\n", sig);
        signal(sig, handler);
    } else if (sig == SIGILL) {
        printf("Caught SIGULL %d in Thread 2\n", sig);
        signal(sig, handler);
    } else if (sig == SIGPWR) {
        printf("Caught SIGPWR %d in Thread 2\n", sig);
        signal(sig, handler);
    } else {
        printf("Caught unknown signal %d in Thread 2\n", sig);
    }
}
void* thread1() {
    int i, count = 0;
    int tid, pid;
    tid = gettid();
    pid = getpid();

    printf("Thread 1: tid = %d, pid = %d started\n", tid, pid);
    for (i = 0; i < COUNT; i++) {
        count += 1;
        printf("Thread 1: step %d\n", count);
        sleep(5);
        pthread_kill(t2, SIGUSR2);
        pthread_kill(t2, SIGUSR1);
        pthread_kill(t2, SIGINT);
        pthread_kill(t2, SIGILL);
    
    }
}
void* thread2() {
    int i, count = 0;
    int tid, pid;
    tid = gettid();
    pid = getpid();
    printf("Thread 2 tid = %d, pid = %d started\n", tid, pid);
    int m = 10;
    for (i = 0; i < m; i++) {
        count += 1;
        sleep(1);
        printf("Thread 2: step %d\n", count);
    }
}
int main() {
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    signal(SIGINT, handler);
    signal(SIGPWR, handler);
    signal(SIGILL, handler);
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
