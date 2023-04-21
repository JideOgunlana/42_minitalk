/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:41:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/21 10:42:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_bonus.h"

t_server	g_received;

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

void	get_client_pid(void)
{
	int			c;
	int			pow;

	pow = 1;
	if (g_received.bit == 8)
	{
		c = ft_binary_to_decimal(g_received.messg/*  + (g_received.counter - 7) */);
		if (c == '$')
			g_received.c_pid_status = 1;
		else
		{
			if (g_received.c_pid_index > 0)
				pow = 10;
			g_received.client_pid = g_received.client_pid * pow + (c - '0');
		}
		++g_received.c_pid_index;
		g_received.bit = 0;
	}
}

void	handle_sig(int signum)
{
	int			c;

	if (signum == SIGUSR1)
		g_received.messg[g_received.bit] = '0';
	else if (signum == SIGUSR2)
		g_received.messg[g_received.bit] = '1';
	g_received.bit += 1;
	if (g_received.c_pid_status == 0)
		get_client_pid();
	if (g_received.bit == 8 && g_received.c_pid_status == 1)
	{
		c = ft_binary_to_decimal(g_received.messg/*  + (g_received.counter - 7) */);
		if (c == '\0')
		{
			g_received.c_pid_status = 0;
			g_received.c_pid_index = 0;
			kill(g_received.client_pid, SIGUSR1);
			g_received.client_pid = 0;
		}
		write(STDOUT_FILENO, &c, 1);
		g_received.bit = 0;
	}
	// ++g_received.counter;
}

int	main(void)
{
	void	(*sig_handler_return)(int);
	int		server_pid;

	g_received.c_pid_status = 0;
	g_received.c_pid_index = 0;
	g_received.client_pid = 0;
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
		pause();
	}
}
