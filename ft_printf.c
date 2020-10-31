/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:33 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/31 19:49:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("a = %d, b = %d", a, b);

int				ft_prt(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int				ft_answer(char *format, va_list ap)
{
	char	*look;
	int		str_len;
	int		i;

	i = 0;
	str_len = 0;
	while (format[i])
	{
		look = ft_strchr(&format[i], '%');
		if (look)
		{
			str_len += ft_prt(&format[i], look);
			ft_printf_chk(&format[i], ap, &str_len);
		}
		else
		{
			str_len += ft_prt(&format[i], ft_strlen(format) - i);
			break ;
		}
		i++;
	}
	return (str_len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			str_len;

	str_len = 0;
	va_start(ap, format);
	if (!(str_len = ft_answer((char *)format, ap)))
		return (_ERROR);
	return (str_len);
}

