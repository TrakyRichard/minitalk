#include "./includes/minitalk.h"

void help()
{
    ft_printf("Usage: ./client [server PID] [message]");
    return;
}

void feedback(int sig)
{
    if (sig == SIGUSR1)
        ft_printf("Message sent to server successfully");
    return;
}

void signal_processing(int pid, char *message)
{
    int j;
    int k;

    while (*message)
    {
        j = 0;
        while (j < 8)
        {
            k = *message >> j & 1;
            if (k == 1)
            {
                if (kill(pid, SIGUSR1) == -1)
                    ft_error("Error: kill() failed");
            }
            else
            {
                if (kill(pid, SIGUSR2) == -1)
                    ft_error("Error: kill() failed");
            }
            j++;
            usleep(500);
        }
        message++;
    }
    send_last_char(pid);
    return;
}

void send_last_char(int pid)
{
    int j;
    int k;

    j = 0;
    while (j < 8)
    {
        k = '\0' >> j & 1;
        if (k == 1)
        {
            if (kill(pid, SIGUSR1) == -1)
                ft_error("Error: kill() failed");
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                ft_error("Error: kill() failed");
        }
        j++;
        usleep(500);
    }
    return;
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        help();
        return (0);
    }
    check_pid(argv[1]);
    pid = ft_atoi(argv[1]);
    signal(SIGUSR1, feedback);
    signal_processing(pid, argv[2]);
    return (0);
}