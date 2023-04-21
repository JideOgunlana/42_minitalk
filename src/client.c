/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:14:53 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/21 10:39:44 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

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
		usleep(400);
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

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int		message_len;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <server_pid> <message>\n");
		exit(1);
	}
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0 || server_pid > INT16_MAX)
		{
			ft_printf("Usage: ./client <server_pid> <message>\n");
			exit(1);
		}
		message_len = ft_strlen(argv[2]);
		parse_message(argv[2], message_len, server_pid);
	}
	return (0);
}
