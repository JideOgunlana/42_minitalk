/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/23 20:36:49 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_width(t_printf *val, const char *format, int i)
{
	int	num;

	while (ft_strchr(DECIMALS, format[i]))
	{
		num = format[i] - '0';
		if (val->width > 0)
			val->width = (val->width * 10) + num;
		else
			val->width = num;
		i++;
	}
	return (i);
}

int	check_flags(t_printf *val, const char *format, int i)
{
	while (!(ft_strchr(FLAGS, format[i])))
	{
		if (format[i] == '#' && i++)
			val->pound = TRUE;
		if (format[i] == ' ' && i++)
			val->spc = TRUE;
		if (format[i] == '+' && i++)
			val->sign = TRUE;
		if (format[i] == '-' && i++)
			val->dash = TRUE;
		if (format[i] == '0' && i++)
			val->zero = TRUE;
		if (format[i] == '.' && i++)
		{
			if (ft_strchr(DECIMALS, format[i]))
				val->point = format[i] - '0';
			i++;
			return (i);
		}
		i = check_width(val, format, i);
	}
	return (i);
}

int	ft_eval(t_printf *val, const char *format, int i)
{
	i = check_flags(val, format, i);
	if (format[i] == 'c')
		ft_print_char(val);
	if (format[i] == 'i' || format[i] == 'd')
		ft_print_num(val);
	if (format[i] == 's')
		ft_print_string(val);
	if (format[i] == 'u')
		ft_print_unsigned_int(val);
	if (format[i] == 'p')
		ft_print_pointer(val);
	if (format[i] == 'x' || format[i] == 'X')
		ft_print_hex(val, format[i]);
	if (format[i] == '%')
		val->tl += write(1, "%", 1);
	return (i);
}
