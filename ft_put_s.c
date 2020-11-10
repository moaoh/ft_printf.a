/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:32:44 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/10 14:26:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char *
// width, minus, zero
int		ft_put_s(t_chk *s, va_list ap)
{
	char	*str;
	int		s_len;
	int		num;

	str = va_arg(ap, char*);
	s_len = ft_strlen(str);
	if (s->f_minus == 1) // '-'
	{
		write(1, str, s_len);
		s_len += ft_width_print(s->width, s_len);
	}
	else
	{
		num = s_len;
		if (s->f_zero == 0)
			s_len += ft_width_print(s->width, s_len);
		else
			s_len += ft_precision_print(s->width, s_len);
		write(1, str, num);
	}

	return (s_len);
}
