// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

    int child = fork();

    if (child < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    if (child == 0)
    {
        printf("hello from the child!\n");
    }
    else
    {
        waitpid(child, NULL, 0);
        printf("goodbye from the parent!\n");
    }

    return 0;
}
