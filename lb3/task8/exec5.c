#include <unistd.h>

#include <stdio.h>

int main (void)

{

char * echo_args[] = { "echo", "child", NULL };

if (!fork ()) {

execvp ("echo", echo_args);

fprintf (stderr, "an error occured\n");

return 1;

}

return 0;

}
