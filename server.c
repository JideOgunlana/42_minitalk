#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_minitalk.h"

void	handler_sig(int);

// handler_sig fxn determines what signal is received and what should be done with this signal
void handler_sig(int signum)
{

	if (signum == SIGUSR1)
	{
		printf("Received SIGUSR1 -> %d\n", signum);
		// exit(0);
	}
    else if(signum == SIGUSR2)
    {
        printf("Received SIGUSR2 -> %d\n", signum);
        // exit(0);
    }
	// else
	// {
	// 	printf("Received signal %d\n", signum);
	// 	return ;
	// }
}

int main()
{
    void (*sig_handler_return) (int);
    sig_handler_return = signal(SIGUSR1, handler_sig);
    if (sig_handler_return == SIG_ERR)
    {
        perror("Signal Error");
        return 1;
    }
    sig_handler_return = signal(SIGUSR2, handler_sig);
    if (sig_handler_return == SIG_ERR)
    {
        perror("Signal Error");
        return 1;
    }
    sig_handler_return = signal(SIGCONT, handler_sig);
    if (sig_handler_return == SIG_ERR)
    {
        perror("Signal Error");
        return 1;
    }
    pid_t pid_s = getpid();
    printf("Server pid is %d\n", pid_s);
    while(1)
    {
        sleep(10);
    }
    // pause();
}
