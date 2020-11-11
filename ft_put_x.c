/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:30:46 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/11 19:52:18 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 16진수 변환 출력
static char			*ft_change(unsigned int temp, int len)
{
	char	*main;
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	main = "0123456789abcdef";
	while (len >= 0)
	{
		str[len] = main[temp % 16];
		temp /= 16;
		len--;
	}
	return (str);
}

static int			ft_x_print(char *x, t_chk *s, int len)
{
	int				x_len;

	x_len = 0;
	x_len += ft_precision_print(s->precision, len);
	write(1, x, ft_strlen(x));
	x_len += ft_strlen(x);
	return (x_len);
}

static int			ft_precision_minus(char *x, t_chk *s, int len)
{
	int				long_len;
	int				x_len;

	x_len = 0;
	long_len = (len >= s->precision) ? len : s->precision;
	if (s->f_minus == 1)
	{
		x_len += ft_x_print(x, s, len);
		x_len += ft_width_print(s->width, long_len);
	}
	else
	{
		if (s->f_zero == 1 && s->precision == 0)
			x_len += ft_precision_print(s->width, long_len);
		else
			x_len += ft_width_print(s->width, long_len);
		x_len += ft_x_print(x, s, len);
	}
	return (x_len);
}

int					ft_put_x(t_chk *s, va_list ap)
{
	unsigned int	temp;
	int				x_len;
	int				x_minus;
	int				len;
	char			*x;

	x_minus = 0;
	x_len = 0;
	temp = va_arg(ap, unsigned int);
	if (temp == 0)
	{
		len = 1;
		if (s->f_point == 1 && s->precision == 0)
			len = 0;
	}
	else
		len = ft_x_size(temp);
	if (!(x = ft_change(temp, len)))
		return (_ERROR);
	x_len += ft_precision_minus(x, s, len);

	return (x_len);
}
