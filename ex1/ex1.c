// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // initialize a value in memory
    int val = 100;

    // create child process (pid will be 0)
    pid_t pid = fork();

    // if fork fails pid will be a negative number
    if (pid < 0)
    {
        printf("fork failed\n");
        exit(1);
    }
    // if pid is 0, it's the child process
    if (pid == 0)
    {
        // value should be 100 since it was initialized before the fork
        printf("child value is: %d\n", val);
        // this should update the value of the parent as well
        val = 10;
        printf("new child value is: %d\n", val); // should return 10 since it's updated
    }
    // this will be the code for the parent process
    else
    {
        // child updating val will not affect the parent's val
        // since processes don't communicate with one another
        // they have their own alloted memory for the process
        // the value would be stored in the stack of each process
        printf("parent value is: %d\n", val);
    }
    return 0;
}
