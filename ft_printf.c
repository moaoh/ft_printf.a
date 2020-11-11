/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:33 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/11 19:21:04 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_percent(char **point)
{
	char		*str;
	int			len;

	len = 0;
	str = *point;
	while (**point != '%' && **point != '\0')
	{
		len++;
		(*point)++;
	}
	return (write(1, str, len));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**point;
	int			str_len;

	va_start(ap, format);
	str_len = 0;
	point = (char **)&format;
	while (**point != '\0')
	{
		str_len += ft_percent(point);
		if (**point == '\0')
			break ;
		str_len += ft_format_type(point, ap);
		(*point)++;
	}
	return (str_len);
}
