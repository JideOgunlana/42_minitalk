/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:33:36 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/07 17:12:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_width_count_helper(t_printf *val, int width_count)
{
	width_count -= 2;
	width_count = ft_width_count(val, width_count);
	if (width_count < 0)
		val->tl += 2;
	val->pound = FALSE;
	return (width_count);
}

int	hex_width_count(t_printf *val, int num, int width_count, char c)
{
	if (val->pound && c == 'x' && num != 0)
	{
		write(1, "0x", 2);
		width_count = hex_width_count_helper(val, width_count);
	}
	if (val->pound && c == 'X' && num != 0)
	{
		write(1, "0X", 2);
		width_count = hex_width_count_helper(val, width_count);
	}
	val->width = 0;
	return (val->width);
}

void	ft_put_hex(unsigned int num, char c, int fd)
{
	if (num < 10)
	{
		num = num + '0';
		ft_putchar_fd(num, fd);
	}
	else
	{
		if (num / 16 != 0)
			ft_put_hex(num / 16, c, fd);
		if ((num % 16) < 10)
			num = (num % 16) + '0';
		else
		{
			if (c == 'x')
				num = ((num % 16) - 10) + 'a';
			if (c == 'X')
				num = ((num % 16) - 10) + 'A';
		}
		ft_putchar_fd(num, fd);
	}
}

void	hex_has_dash_helper(t_printf *val, int width_count)
{
	if (width_count < 0 && val->pound)
		val->tl += 2;
	val->pound = FALSE;
}

void	hex_has_dash(t_printf *val, int num, char c, int width_count)
{
	if (c == 'x' && num != 0)
	{
		if (val->pound)
			width_count -= write(1, "0x", 2);
		ft_put_hex(num, c, 1);
		width_count = ft_width_count(val, width_count);
		hex_has_dash_helper(val, width_count);
	}
	if (c == 'X' && num != 0)
	{
		if (val->pound)
			width_count -= write(1, "0X", 2);
		ft_put_hex(num, c, 1);
		width_count = ft_width_count(val, width_count);
		hex_has_dash_helper(val, width_count);
	}
	else if (num == 0)
	{
		write(1, "0", 1);
		width_count = ft_width_count(val, width_count);
		val->pound = FALSE;
	}
	val->width = 0;
}
