/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:18 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/09 20:59:26 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char
// minus , zero , width
int		ft_put_c(t_chk *s, va_list ap)
{
	char	c;
	int		c_len;

	if (s->type == 'c')
		c = (char)va_arg(ap, int); // 97
	else if (s->type == '%')
		c = '%';
	if (s->f_minus == 1) // '-'
	{
		write(1, &c, 1);
		ft_width_print(s->width, 1);
	}
	else
	{
		ft_width_print(s->width, 1);
		write(1, &c, 1);
	}
	if (s->width >= 1)
		c_len = s->width - 1;
	else
		c_len = 1;
	if (c == '\0')
		c_len++;
	return (c_len);
}
