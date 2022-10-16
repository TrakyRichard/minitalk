#ifndef MINI_TALK_H
# define MINI_TALK_H
# include <unistd.h>
# include <stdio.h>
# include "./ft_printf.h"
# include <signal.h>
# include "./libft.h"

void check_pid(char *pid);
void ft_error(char *str);
void help();
void handle_sigurs(int sig, siginfo_t *info, void *ucontext);
int main();
void feedback(int sig);
void create_pid();
int client(int argc, char **argv);
void send_last_char(int pid);

#endif