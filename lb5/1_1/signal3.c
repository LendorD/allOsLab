#include <sys/signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int nextSig = 0;
int sigOrder[10];

void handler(int signo, siginfo_t *info, void *context) {
  sigOrder[nextSig++] = signo;
  printf("Recivied signal %d with value %d\n",signo, info->si_value.sival_int);

}

void handler2(int signo) {
  sigOrder[nextSig++] = signo;
  printf("signal2 %d\n", signo);
}


int main() {
  sigset_t mask;
  sigset_t oldMask;
  struct sigaction act;
  int i;
  sigemptyset(&mask);
  sigaddset(&mask, SIGRTMIN);
  sigaddset(&mask, SIGRTMIN+1);
  sigaddset(&mask, SIGUSR1);
  sigaddset(&mask, SIGRTMAX-7);
  sigaddset(&mask, SIGBUS);
  sigaddset(&mask, SIGRTMAX);
  sigaddset(&mask, SIGINT);

  act.sa_sigaction = handler;

  sigemptyset(&act.sa_mask);

  act.sa_flags = SA_SIGINFO;

   sigaction(SIGRTMIN, &act, NULL);
  sigaction(SIGRTMIN+1, &act, NULL);
  sigaction(SIGRTMAX, &act, NULL);
  sigaction(SIGRTMAX-7, &act, NULL);
  sigaction(SIGBUS, &act, NULL);
  sigprocmask(SIG_BLOCK, &mask, &oldMask);

  union sigval value;
  value.sival_int = 1;
  sigqueue(getpid(), SIGRTMIN+1, value);
   value.sival_int = 2;
  sigqueue(getpid(), SIGRTMIN, value);
   value.sival_int = 3;
  sigqueue(getpid(), SIGRTMAX-7, value);
 sigqueue(getpid(), SIGBUS, value);
  value.sival_int = 4;
  sigqueue(getpid(), SIGRTMIN, value);

  value.sival_int = 5;
  sigqueue(getpid(), SIGRTMAX, value);
  value.sival_int = 6;
  sigqueue(getpid(), SIGRTMIN+1, value);
  sigprocmask(SIG_SETMASK, &oldMask, NULL);
 
  return 0;
}

