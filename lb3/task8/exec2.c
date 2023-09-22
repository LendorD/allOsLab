#include <unistd.h>

#include <stdio.h>

int main (void)

{

if (!fork ()) {

execlp ("echo", "echo", "child", NULL);

fprintf (stderr, "an error occured\n");

return 1;

}

return 0;

}
