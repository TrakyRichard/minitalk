#include "./includes/minitalk.h"

void create_pid()
{
    int pid;

    pid = getpid();
    ft_printf("Server PID: %d \n", pid);
    return;
}

void handle_sigurs(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    static int i = 0;
    static char c = 0;

    if (sig == SIGUSR1)
        c += 1 << i;
    i++;
    if (i == 8)
    {
        if (c == '\0')
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
    return;
}

int main()
{
    create_pid();
    struct sigaction act_sa;
    act_sa.sa_sigaction = handle_sigurs;
    act_sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &act_sa, NULL) == -1)
        ft_error("Error: sigaction() failed");
    
    if (sigaction(SIGUSR2, &act_sa, NULL) == -1)
        ft_error("Error: sigaction() failed");
    while (1)
        pause();
    return (0);
}