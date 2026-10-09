#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t pid;

    char message[] = "Graphic Era";
    char buffer[100] = {0};

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        close(fd[0]);

        if (write(fd[1], message, strlen(message) + 1) == -1)
        {
            perror("write");
            close(fd[1]);
            exit(EXIT_FAILURE);
        }

        printf("Child wrote: %s\n", message);

        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(fd[1]);

        if (read(fd[0], buffer, sizeof(buffer)) == -1)
        {
            perror("read");
            close(fd[0]);
            wait(NULL);
            return EXIT_FAILURE;
        }

        printf("Parent read: %s\n", buffer);

        close(fd[0]);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}