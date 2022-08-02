/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:41:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/08/02 12:27:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

t_server	*val;

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		isvalid(char c, int base)
{
	char	digits[17] = "0123456789abcdef";
	char	digits2[17] = "0123456789ABCDEF";

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

void	handle_sig(int signum)
{
	int	c;

	val->bit += 1;
	if (signum == SIGUSR1)
		val->messg[val->counter] = '0';
	else if (signum == SIGUSR2)
		val->messg[val->counter] = '1';
	if (val->bit == 8)
	{
		c = ft_atoi_base(val->messg, 2);
		if (c == 0)
			ft_printf("true");
		write(STDOUT_FILENO, &c, 1);
		val->bit = 0;
	}
	val->counter++;
	// ft_printf("%d\n", val->counter);
	// static int	c = 0;
	// static int	bits = 0;
	// int			i;
	// int			n;

	// if (signum == SIGUSR1)
	// {
	// 	i = 1;
	// 	n = 1;
	// 	while (i++ < (8 - bits))
	// 		n *= 2;
	// 	c += n;
	// }
	// bits++;
	// if (bits == 8)
	// {
	// 	ft_printf("%c", 255 - c);
	// 	bits = 0;
	// 	c = 0;
	// }
}

int	main(void)
{
	void	(*sig_handler_return)(int);
	int		server_pid;

	server_pid = getpid();
	val = (t_server *) malloc(sizeof(t_server));
	if (!val)
		return (1);
	sig_handler_return = signal(SIGUSR1, handle_sig);
	if (sig_handler_return == SIG_ERR)
		return (1);
	sig_handler_return = signal(SIGUSR2, handle_sig);
	if (sig_handler_return == SIG_ERR)
		return (1);
	ft_printf("Server PID is: %d\n", server_pid);
	while (1)
	{
		sleep(10);
	}
}
