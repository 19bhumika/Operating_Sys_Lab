#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        printf("I am Child\n");
        printf("Child PID = %d\n", (int)getpid());

        exit(5);
    }
    else
    {
        wait(&status);

        printf("I am Parent\n");
        printf("Child PID = %d\n", (int)pid);

        if (WIFEXITED(status))
        {
            printf("Child exit status = %d\n",
                   WEXITSTATUS(status));
        }
    }

    return EXIT_SUCCESS;
}