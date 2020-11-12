/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:54:42 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/12 17:00:06 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_change(long long temp, int len)
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

static int		ft_p_print(char *p, t_chk *s, int len)
{
	int				p_len;

	p_len = 0;
	write(1, "0x", 2);
	p_len += ft_precision_print(s->precision, len);
	write(1, p, ft_strlen(p));
	p_len += ft_strlen(p) + 2;
	return (p_len);
}

static int		ft_precision_minus(char *p, t_chk *s, int len)
{
	int				long_len;
	int				p_len;

	p_len = 0;
	long_len = (len >= s->precision) ? len : s->precision;
	if (s->f_minus == 1)
	{
		p_len += ft_p_print(p, s, len);
		p_len += ft_width_print(s->width, long_len + 2);
	}
	else
	{
		if (s->f_zero == 1 && s->precision == 0)
			p_len += ft_precision_print(s->width, long_len + 2);
		else
			p_len += ft_width_print(s->width, long_len + 2);
		p_len += ft_p_print(p, s, len);
	}
	return (p_len);
}

int				ft_put_p(t_chk *s, va_list ap)
{
	long long			temp;
	int					p_len;
	int					p_minus;
	int					len;
	char				*p;

	p_minus = 0;
	p_len = 0;
	temp = va_arg(ap, long long);
	if (temp == 0)
	{
		len = 1;
		if (s->f_point == 1 && s->precision == 0)
			len = 0;
	}
	else
		len = ft_p_size(temp);
	if (!(p = ft_change(temp, len)))
		return (_ERROR);
	p_len += ft_precision_minus(p, s, len);
	free(p);
	return (p_len);
}
