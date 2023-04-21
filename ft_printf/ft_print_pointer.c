/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:36:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/04 20:03:24 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_l(unsigned long p)
{
	if (p < 16)
		return (1);
	return (ft_pointer_l(p / 16) + 1);
}

void	ft_put_ptr(unsigned long p, int fd)
{
	if (p < 10)
	{
		p = p + '0';
		ft_putchar_fd(p, fd);
	}
	else
	{
		if (p / 16 != 0)
			ft_put_ptr(p / 16, fd);
		if ((p % 16) < 10)
			p = (p % 16) + '0';
		else
			p = ((p % 16) - 10) + 'a';
		ft_putchar_fd(p, fd);
	}
}

void	p_dash_flag(unsigned long p, int width_count, t_printf *val)
{
	write(1, "0x", 2);
	ft_put_ptr(p, 1);
	val->tl += ft_pointer_l(p) + 2;
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
}

void	ft_print_pointer(t_printf *val)
{
	unsigned long	p;
	int				width_count;

	p = va_arg(val->args, unsigned long);
	width_count = val->width - ft_pointer_l(p) - 2;
	if (width_count > 0)
		val->tl += width_count;
	if (val->dash)
	{
		p_dash_flag(p, width_count, val);
		val->dash = FALSE;
		return ;
	}
	val->tl += ft_pointer_l(p) + 2;
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
	write(1, "0x", 2);
	ft_put_ptr(p, 1);
}
