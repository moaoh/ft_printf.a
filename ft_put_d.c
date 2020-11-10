/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:15 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/09 21:11:15 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_minus(long long *d, int *d_minus)
{
	if (*d < 0)
	{
		*d *= -1;
		*d_minus = 1;
		return (1);
	}
	return (0);
}

static int		ft_d_size(long long d)
{
	int				count;

	count = 0;
	while (d >= 1)
	{
		d /= 10;
		count++;
	}
	return (count);
}

static int		ft_int_print(long long d, t_chk *s, int len, int d_minus)
{
	int				d_len;

	d_len = 0;
	if (d_minus == 1) // - 출력
		write(1, "-", 1);
	d_len += ft_precision_print(s->precision, len);
	if (d != 0)
		d_len += ft_prt_int(d);
	return (d_len);
}

static int		ft_precision_minus(long long d, t_chk *s, int len, int d_minus)
{
	int				long_len;
	int				d_len;

	d_len = 0;
	long_len = (len >= s->precision) ? len : s->precision;
	if (s->f_minus == 0) // zero에 길이는 len - width 값.
	{
		d_len += ft_width_print(s->width, long_len);
		d_len += ft_int_print(d, s, len , d_minus);
	}
	else
	{
		d_len += ft_int_print(d, s, len , d_minus);
		d_len += ft_width_print(s->width, long_len);
	}
	return (d_len);
}
int		ft_put_d(t_chk *s, va_list ap)
{
	long long		d;
	int				len;
	int				d_len; // 최종 길이.
	int				d_minus;

	d_minus = 0;
	d_len = 0;
	d = (long long)va_arg(ap, int);
	d_len += ft_minus(&d, &d_minus); // 음수인지 양수인지 판별
	if (d == 0 && s->precision != 0)
		len = 1;
	else
		len = ft_d_size(d);
	len += d_minus;
	d_len += ft_precision_minus(d, s, len, d_minus);
	return (d_len);
}
