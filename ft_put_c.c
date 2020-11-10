/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:18 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/10 14:28:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char
// minus , zero , width
int		ft_put_c(t_chk *s, va_list ap)
{
	char	c;
	int		c_len;

	c_len = 1;
	if (s->type == 'c')
		c = (char)va_arg(ap, int); // 97
	else if (s->type == '%')
		c = '%';
	if (s->f_minus == 1) // '-'
	{
		write(1, &c, 1);
		c_len += ft_width_print(s->width, 1);
	}
	else
	{	if (s->f_zero == 0)
			c_len += ft_width_print(s->width, 1);
		else
			c_len += ft_precision_print(s->width, 1);
		write(1, &c, 1);
	}
	if (c == '\0')
		c_len++;
	return (c_len);
}
