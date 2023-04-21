/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:11:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/25 17:25:15 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_dash_flag(char c, int width_count, t_printf *val)
{
	val->tl += write(1, &c, 1);
	while (width_count > 0)
	width_count = ft_width_count(val, width_count);
	if (val->width > 1)
		val->tl += val->width - 1;
	val->width = width_count;
}

void	ft_print_char(t_printf *val)
{
	char	c;
	int		width_count;

	width_count = val->width - 1;
	c = va_arg(val->args, int);
	if (val->dash)
	{
		c_dash_flag(c, width_count, val);
		val->dash = FALSE;
		return ;
	}
	if (val->width > 1)
		val->tl += width_count;
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
	val->tl += write(1, &c, 1);
}
