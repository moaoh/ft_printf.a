/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:32:44 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/11 21:07:40 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char *
// width, minus, zero

int		ft_precision_s(int precision, int len)
{
	int		precision_len;

	precision_len = precision - len;
	if (precision > 0)
	{
		while (precision - len > 0)
		{
			write(1, "0", 1);
			precision--;
		}
	}
	if (precision_len < 0)
		precision_len = 0;
	return (precision_len);
}

int		ft_put_s(t_chk *s, va_list ap)
{
	char	*str;
	int		s_len;
	int		num;

	num = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
	{
		str = "(null)";
		s_len = 6;
	}
	else
		s_len = ft_strlen(str);
	if (s->f_point == 1 && s->precision < s_len)
		s_len = (s->precision < 0) ? s_len : s->precision;
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
			s_len += ft_precision_s(s->width, s_len);
		write(1, str, num);
	}

	return (s_len);
}
