#include <unistd.h>

#include <stdio.h>

extern char ** environ;

int main (void)

{

if (!fork ()) {

execle ("/bin/echo", "echo", "child", NULL, environ);

fprintf (stderr, "an error occured\n");

return 1;

}

return 0;

}

−
