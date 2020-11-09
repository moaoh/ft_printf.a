/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:19 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/09 20:50:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// unsigned int
static int		ft_d_size(unsigned int d)
{
	int		count;

	count = 0;
	while (d >= 1)
	{
		d /= 10;
		count++;
	}
	return (count);
}

static int		ft_int_print(unsigned int d, t_chk *s, int len)
{
	int		d_len;
	d_len = 0;
	d_len += ft_precision_print(s->precision, len);
	d_len += ft_prt_uint(d);
	return (d_len);
}

static int		ft_precision_minus(unsigned int d, t_chk *s, int len)
{
	int		long_len;
	int		d_len;

	d_len = 0;
	long_len = (len >= s->precision) ? len : s->precision;
	if (s->f_minus == 0) // zero에 길이는 len - width 값.
	{
		d_len += ft_width_print(s->width, long_len);
		d_len += ft_int_print(d, s, len);
	}
	else
	{
		d_len += ft_int_print(d, s, len);
		d_len += ft_width_print(s->width, long_len);
	}
	return (d_len);
}
int		ft_put_u(t_chk *s, va_list ap)
{
	unsigned int		d;
	int				len;
	int				d_len; // 최종 길이.
	int				d_minus;

	d_minus = 0;
	d_len = 0;
	d = (unsigned int)va_arg(ap, int);
	if (d == 0 && s->precision != 0)
		len = 1;
	else
		len = ft_d_size(d);
	d_len += ft_precision_minus(d, s, len);
	return (d_len);
}
