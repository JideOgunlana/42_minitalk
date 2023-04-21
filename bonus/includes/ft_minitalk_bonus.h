/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:40:29 by bogunlan          #+#    #+#             */
/*   Updated: 2023/04/21 10:43:12 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H
# define END_MESSAGE "00000000"

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../../ft_printf/ft_printf.h"

typedef struct s_server
{
	int		bit;
	int		counter;
	int		client_pid;
	int		c_pid_status;
	int		c_pid_index;
	int		end_client;
	char	c;
	char	c_pid[10];
	char	messg[];
}				t_server;

// t_server	*received(void);
void		ft_client_error(void);
int			is_pid_invalid(char *pid);

#endif