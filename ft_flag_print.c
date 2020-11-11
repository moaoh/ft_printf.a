/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:56:49 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/11 20:58:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_prt_uint(unsigned int d)
{
	char	*str;

	str = ft_itoa((long long)d);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int			ft_prt_int(long long d)
{
	char	*str;

	str = ft_itoa((long long)d);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int			ft_width_print(int width, int len)
{
	int		width_len;

	width_len = width - len;
	if (width_len < 0)
		width_len = 0;
	if (width > 0)
	{
		while (width - len > 0)
		{
			write(1, " ", 1);
			width--;
		}
	}
	return (width_len);
}

int			ft_precision_print(int	precision, int len)
{
	int		precision_len;

	precision_len = precision - len;
	if (precision_len < 0)
		precision_len = 0;
	if (precision > 0)
	{
		while (precision - len > 0)
		{
			write(1, "0", 1);
			precision--;
		}
	}
	return (precision_len);
}

t_chk		*ft_chk_bzero(void)
{
	t_chk	*s;

	if (!(s = (t_chk *)malloc(sizeof(t_chk) * 1)))
		return (NULL);
	s->f_minus = 0;
	s->f_zero = 0;
	s->width = 0;
	s->precision = 0;
	s->f_point = 0;
	s->type = '\0';
	return (s);
}
