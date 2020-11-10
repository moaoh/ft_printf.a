/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:54:42 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/10 19:59:22 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// d 와 같음

static int		ft_x_size(long long x)
{
	int				count;

	count = 0;
	while (x >= 1)
	{
		x /= 16;
		count++;
	}
	return (count);
}

// 16진수 변환 출력
static char		*ft_change(long long temp, int len)
{
	char	*main;
	char	*str;
	int		i;
	int		m;

	str = (char *)malloc(len + 1);
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

static int		ft_x_print(char *x, t_chk *s, int len)
{
	int				x_len;

	x_len = 0;
	write(1, "0x", 2);
	x_len += ft_precision_print(s->precision, len);
	write(1, x, ft_strlen(x));
	x_len += ft_strlen(x) + 2;
	return (x_len);
}

static int		ft_precision_minus(char *x, t_chk *s, int len)
{
	int				long_len;
	int				x_len;

	x_len = 0;
	long_len = (len >= s->precision) ? len : s->precision;
	if (s->f_minus == 0) // zero에 길이는 len - width 값.
	{
		x_len += ft_width_print(s->width, long_len + 2);
		x_len += ft_x_print(x, s, len);
	}
	else
	{
		x_len += ft_x_print(x, s, len);
		x_len += ft_width_print(s->width, long_len + 2);
	}
	return (x_len);
}

int				ft_put_p(t_chk *s, va_list ap)
{
	long long		temp;
	int					x_len;
	int					x_minus;
	int					len;
	char				*x;

	x_minus = 0;
	x_len = 0;
	temp = va_arg(ap, long long);
	if (temp == 0 && s->precision != 0)
		len = 1;
	else
		len = ft_x_size(temp);
	x = ft_change(temp, len);
	x_len += ft_precision_minus(x, s, len);

	return (x_len);
}
