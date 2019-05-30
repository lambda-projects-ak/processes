// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // open text.txt
    // FILE *fopen(const char *filename, const char *mode)
    FILE *fp = fopen("text.txt", "w+");

    // fork process start
    int child = fork();

    if (child < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    // can both parent & child access file descriptor returned by fopen()?
    // yes.
    // what happens when they are written to the file concurrently?
    // the file receives both writes in the order that the processes occur
    if (child == 0)
    {
        fprintf(fp, "%s", "This is the child\n");
    }
    else
    {
        fprintf(fp, "%s", "This is the parent\n");
    }

    fclose(fp);
    return 0;
}
