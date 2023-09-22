#include <signal.h>
#include <pthread.h>
#include <stdio.h>
pthread_t t1, t2;
void* thread1()
{
    for(int i = 0; i <= 5; i++){
        printf("Thread_1 is started\n");	
        printf("time for Thread 1: %d \n", i);
        sleep(5);	
    }
    

}
void* thread2()
{
    for(int i = 0; i <= 5; i++){
        printf("Thread_2 is started\n");	
        printf("time for Thread 2: %d \n", i);	
        sleep(1);
    }
    
}
void main()
{
system("ps axhf > file.txt");
pthread_create(&t1, NULL, thread1, NULL);
pthread_create(&t2, NULL, thread2, NULL);
system("ps axhf >> file.txt");
pthread_join(t1, NULL);
pthread_join(t2, NULL);
system("ps axhf >> file.txt");
}
