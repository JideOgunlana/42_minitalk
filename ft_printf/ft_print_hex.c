/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:38:06 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/06 11:42:38 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	if (num < 16)
		return (1);
	return (ft_hex_len(num / 16) + 1);
}

void	ft_print_hex(t_printf *val, char c)
{
	unsigned int	num;
	int				width_count;

	num = va_arg(val->args, unsigned int);
	val->tl += ft_hex_len(num);
	width_count = val->width - ft_hex_len(num);
	if (width_count > 0)
		val->tl += width_count;
	while (width_count > 0 && !val->pound && !val->dash)
	{
		if (val->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width_count--;
	}
	if (val->dash)
	{
		hex_has_dash(val, num, c, width_count);
		val->dash = FALSE;
		return ;
	}
	width_count = hex_width_count(val, num, width_count, c);
	val->width = width_count;
	ft_put_hex(num, c, 1);
}
