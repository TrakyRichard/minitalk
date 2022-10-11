#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int x = 0;

void handle_sigurs1(int sig)
{
    if (x == 0)
        printf("\n(HINT)Remind that multiplication is the same as addition repeated n times\n");
    return ;
}

int main()
{

    int pid = fork();

    if (pid == 0)
    {
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else
    {
        signal(SIGUSR1, handle_sigurs1);
        printf("What is the value of the multiplication of 3 by 5: ");
        scanf("%d", &x);

        if (x == 15)
            printf("Correct!\n");
        else
            printf("Wrong!\n");
    }
    return (0);
}