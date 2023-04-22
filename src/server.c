/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:41:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/22 13:00:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

int	ft_binary_to_decimal(const char *str)
{
	int	result;
	int	starting_power;
	int	power;
	int	i;

	result = 0;
	i = 0;
	power = 1;
	while (str[i] != '\0')
	{
		starting_power = 8;
		while (starting_power - i > 1)
		{
			power *= 2;
			starting_power--;
		}
		result = result + ((str[i] - '0') * power);
		power = 1;
		i++;
	}
	return (result);
}

void	handle_sig(int signum)
{
	static t_server	g_received;
	int			c;

	if (signum == SIGUSR1)
		g_received.messg[g_received.bit] = '0';
	else if (signum == SIGUSR2)
		g_received.messg[g_received.bit] = '1';
	g_received.bit += 1;
	if (g_received.bit == 8)
	{
		c = ft_binary_to_decimal(g_received.messg/*  + (g_received.counter - 7) */);
		write(STDOUT_FILENO, &c, 1);
		g_received.bit = 0;
	}
	// g_received.counter++;
}

int	main(int argc, char **argv)
{
	void	(*sig_handler_return)(int);
	int		server_pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\e[33mServer usage:\e[0m ./server\n");
		exit(1);
	}
	server_pid = getpid();
	sig_handler_return = signal(SIGUSR1, handle_sig);
	if (sig_handler_return == SIG_ERR)
		return (1);
	sig_handler_return = signal(SIGUSR2, handle_sig);
	if (sig_handler_return == SIG_ERR)
		return (1);
	ft_printf("\e[33mServer PID is: \e[0m\e[34m%d\e[0m\n", server_pid);
	while (1)
	{
		sleep(10);
	}
}
