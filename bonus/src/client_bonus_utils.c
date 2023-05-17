/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:02:06 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/15 11:14:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk_bonus.h"

void	ft_client_error(void)
{
	ft_putstr_fd("\e[33mUsage:\e[0m ./client <server_pid> <message>\n", STDERR_FILENO);
	exit(1);
}

int	is_pid_invalid(char *pid)
{
	int	i;

	i = 0;
	if (pid[i] == '\0')
		return (1);
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]) && !ft_atoi(&pid[i]))
			return (1);
		i++;
	}
	return (0);
}
