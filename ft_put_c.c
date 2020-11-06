/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:18 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/06 20:08:24 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char
// minus , zero , width
int		ft_put_c(t_chk *s, va_list ap)
{
	char	c;
	int		a;

	if (s->type == 'c')
		c = (char)va_arg(ap, int); // 97
	else if (s->type == '%')
		c = '%';
	if (s->f_minus == 1)
	{
		write(1, &c, 1);
		ft_width_print(s->width, 1);
	}
	else
	{
		ft_width_print(s->width, 1);
		write(1, &c, 1);
	}
	// 아스키코드값을 어떻게 문자로 바꾸는가.
	return (0);
}
