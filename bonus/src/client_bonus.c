/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:14:53 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/21 16:06:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_bonus.h"

int	g_stop_client;

void	send_signal(char *res, pid_t server_pid)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == '0')
			if (kill(server_pid, SIGUSR1) != 0)
				exit(1);
		if (res[i] == '1')
			if (kill(server_pid, SIGUSR2) != 0)
				exit(1);
		usleep(7000); // time made slower due to different machines
		i++;
	}
}

void	parse_message(char *message, int message_len, pid_t server_pid)
{
	int		mssg_index;
	int		i;
	int		j;
	char	*res;

	mssg_index = 0;
	while (mssg_index < message_len)
	{
		i = 0;
		j = 7;
		res = (char *) malloc(sizeof(char) * 8 + 1);
		if (!res)
			return ;
		res[8] = '\0';
		while (i < 8)
		{
			res[j] = (message[mssg_index] + 256) % 2 + '0';
			message[mssg_index] >>= 1;
			j--;
			i++;
		}
		send_signal(res, server_pid);
		free(res);
		mssg_index++;
	}
}

void	handle_server_sig(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("\e[32mmessage received\e[0m\n");
		g_stop_client = 1;
	}
}

void	create_messg(int argc, char *argv[], char *client_pid)
{
	pid_t	server_pid;
	int		message_len;

	if (argc != 3)
		ft_client_error();
	else
	{
		if (is_pid_invalid(argv[1]))
			ft_client_error();
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0 || server_pid > INT16_MAX)
			ft_client_error();
		message_len = ft_strlen(argv[2]);
		parse_message(client_pid, ft_strlen(client_pid), server_pid);
		parse_message(argv[2], message_len, server_pid);
		send_signal(END_MESSAGE, server_pid);
	}	
}

int	main(int argc, char *argv[])
{
	char	*client_pid;
	void	(*sig_handler_return)(int);

	g_stop_client = 0;
	client_pid = ft_itoa((int) getpid());
	client_pid = ft_strjoin(client_pid, "$");
	sig_handler_return = signal(SIGUSR1, handle_server_sig);
	if (sig_handler_return == SIG_ERR)
		return (1);
	create_messg(argc, argv, client_pid);
	while (!g_stop_client)
	{
		pause();
	}
	return (0);
}
