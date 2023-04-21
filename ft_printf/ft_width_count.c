/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:50:38 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/05 18:46:45 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_count(t_printf *val, int width_count)
{
	while (width_count > 0)
	{
		if (val->zero && !val->dash)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width_count--;
	}
	val->zero = FALSE;
	return (width_count);
}
