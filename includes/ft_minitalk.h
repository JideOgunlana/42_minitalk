/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:20:29 by bogunlan          #+#    #+#             */
/*   Updated: 2023/05/15 10:21:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# define END_MESSAGE "00000000"


# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_server
{
	int		bit;
	char	c;
	char	messg[];
}				t_server;

#endif