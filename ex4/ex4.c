// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    char *args[] = {"/bin/ls", NULL};
    int child = fork();

    if (child < 0)
    {
        printf("fork failed\n");
        exit(1);
    }

    if (child == 0)
    {
        execv(args[0], args);
        printf("This shouldn't print\n");
    }

    else
    {
        waitpid(child, NULL, 0);
    }

    return 0;
}
