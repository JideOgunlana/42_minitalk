/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:17:59 by bogunlan          #+#    #+#             */
/*   Updated: 2022/05/23 20:39:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 1
# define FALSE 0
# define FLAGS "csdiupxX%"
# define DECIMALS "0123456789"

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_printf
{
	va_list	args;
	int		width;
	int		zero;
	int		point;
	int		dash;
	int		tl;
	int		sign;
	int		perc;
	int		spc;
	int		pound;
}				t_printf;

int			ft_printf(const char *format, ...);
t_printf	*ft_intialize(t_printf *val);
int			ft_eval(t_printf *val, const char *format, int i);
void		ft_print_char(t_printf *val);
void		ft_print_num(t_printf *val);
void		ft_print_string(t_printf *val);
void		ft_print_pointer(t_printf *val);
void		ft_print_unsigned_int(t_printf *val);
void		ft_print_hex(t_printf *val, char c);
int			ft_width_count(t_printf *val, int width_count);
void		ft_put_hex(unsigned int num, char c, int fd);
void		hex_has_dash_helper(t_printf *val, int width_count);
void		hex_has_dash(t_printf *val, int num, char c, int width_count);
int			hex_width_count(t_printf *val, int num, int width_count, char c);
int			hex_width_count_helper(t_printf *val, int width_count);

#endif