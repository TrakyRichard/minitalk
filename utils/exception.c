#include "../includes/minitalk.h"

void ft_error(char *str)
{
    write(1, str, ft_strlen(str));
    exit(1);
}


void check_pid(char *pid)
{
    int i;

    i = 0;
    while (pid[i] != '\0')
    {
        if (pid[i] < '0' || pid[i] > '9')
            ft_error("Error: PID must be a number");
        i++;
    }
    return ;
}