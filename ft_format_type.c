/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:40:37 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/12 16:52:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_format_type(char **point, va_list ap)
{
	t_chk	*s;
	int		str_len;

	str_len = 0;
	s = ft_flag_chk(point, ap);
	if (s->type == 'c')
		str_len += ft_put_c(s, ap);
	if (s->type == 's')
		str_len += ft_put_s(s, ap);
	if (s->type == 'p')
		str_len += ft_put_p(s, ap);
	if (s->type == 'd')
		str_len += ft_put_d(s, ap);
	if (s->type == 'i')
		str_len += ft_put_d(s, ap);
	if (s->type == 'u')
		str_len += ft_put_u(s, ap);
	if (s->type == 'x')
		str_len += ft_put_x(s, ap);
	if (s->type == 'X')
		str_len += ft_put_xlarge(s, ap);
	if (s->type == '%')
		str_len += ft_put_c(s, ap);
	free(s);
	return (str_len);
}
