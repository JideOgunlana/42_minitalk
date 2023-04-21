/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:38 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/25 17:24:40 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_dash_flag(char *str, int width_count, t_printf *val, int str_len)
{
	ft_putstr_fd(str, 1);
	width_count = ft_width_count(val, width_count);
	if (val->width > str_len)
		val->tl += val->width - str_len;
	val->width = width_count;
}

void	str_is_null(t_printf *val)
{
	int	width_count;

	width_count = 0;
	if (val->width <= 6)
		val->tl += write(1, "(null)", 6);
	else
	{
		width_count = val->width - 6;
		width_count = ft_width_count(val, width_count);
		val->tl = val->width;
		write(1, "(null)", 6);
	}
}

void	ft_print_string(t_printf *val)
{
	char	*str;
	int		width_count;
	int		str_len;

	str = va_arg(val->args, char *);
	if (str == NULL)
	{
		str_is_null(val);
		return ;
	}
	str_len = ft_strlen(str);
	val->tl += str_len;
	width_count = val->width - str_len;
	if (val->dash)
	{
		str_dash_flag(str, width_count, val, str_len);
		val->dash = FALSE;
		return ;
	}
	if (val->width > str_len)
		val->tl += width_count;
	width_count = ft_width_count(val, width_count);
	val->width = width_count;
	ft_putstr_fd(str, 1);
}
