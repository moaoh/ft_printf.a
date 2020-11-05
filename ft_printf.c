/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:33 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/05 19:38:24 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("a = %d, b = %d", a, b);

int				ft_percent(char **format)
{
	char		*str;
	int			len;

	len = 0;
	str = *format;
	while (**format != '%' && **format != '\0')
	{
		len++;
		(*format)++;
	}
	return (write(1, str, len - 1));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**point;
	int			str_len;

	str_len = 0;

	va_start(ap, format);
	**point = &format;
	while (**point != '\0')
	{
		str_len += ft_percent(point);
		ft_printf_format_type(point, ap, &str_len);
		(*point)++;
	}
	return (str_len);
}

