/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:33 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/04 16:40:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("a = %d, b = %d", a, b);

int				ft_look_percent(char *format, char c)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_answer(char *format, va_list ap)
{
	int		look;
	int		str_len;
	int		i;

	str_len = 0;
	while (format[i])
	{
		look = ft_look_percent(&format[i], '%');
		if (look != -1)
		{
			str_len += ft_prt(&format[i], look);
			ft_printf_format_type(&format[i], ap, &str_len);
			i += look;
		}
		else
		{
			str_len += ft_prt(&format[i], ft_strlen(format) - i);
			break ;
		}
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

