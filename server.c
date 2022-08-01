#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_minitalk.h"

t_client *val;

int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}

void	handler_sig(int);

// handler_sig fxn determines what signal is received and what should be done with this signal

// void	handler_sig(int signum)
// {
// 	static int	c = 0;
// 	static int	bits = 0;
// 	int			i;
// 	int			n;

// 	if (signum == SIGUSR1)
// 	{
// 		i = 1;
// 		n = 1;
// 		while (i++ < (8 - bits))
// 			n *= 2;
// 		c += n;
// 	}
// 	bits++;
// 	if (bits == 8)
// 	{
// 		write(1, &c, 1);
// 		bits = 0;
// 		c = 0;
// 	}
// }

void handler_sig(int signum)
{
    val->bit += 1;
	if (signum == SIGUSR1)
	{
        // val->bit += 1;
        // val->s[val->i] = SIGUSR1 + '0';
        val->mesg[val->i] = '0'; 
		// printf("Received SIGUSR1 -> %d\n", signum);
		// exit(0);
	}
    else if(signum == SIGUSR2)
    {
        // val->bit += 1;
        // val->s[val->i] = SIGUSR2 + '0';
        val->mesg[val->i] = '1';

        // printf("Received SIGUSR2 -> %d\n", signum);
        // exit(0);
    }
    if (val->bit == 8)
    {
        // printf("%s\n", val->mesg);
        int c = ft_atoi_base(val->mesg, 2);
        // printf("%s\n", val->mesg);
        write(1, &c, 1);
        val->bit = 0;
    }
    // printf("**%d**\n", val->bit);
    // printf("##%d##\n", val->i);
    val->i++;
}
 

int main()
{
    val = (t_client *) malloc(sizeof(t_client));
    if (!val)
        return 1;
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
    pid_t pid_s = getpid();
    printf("Server pid is %d\n", pid_s);
    while(1)
    {
        sleep(10);
    }
    // pause();
}
