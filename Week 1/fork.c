#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", (int)getpid());
        printf("Parent PID = %d\n", (int)getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", (int)getpid());
        printf("Child PID = %d\n", (int)pid);
    }

    return EXIT_SUCCESS;
}