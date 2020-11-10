/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:40:37 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/10 14:00:33 by junmkang         ###   ########.fr       */
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
	// printf("\nminus = %d\n", s->f_minus);
	// printf("f_zero = %d\n", s->f_zero);
	// printf("width = %d\n", s->width);
	// printf("length = %d\n", s->length);
	// printf("f_point = %d\n", s->f_point);
	// printf("type = %c\n", s->type);
	// 이후 type에 따라서 값을 들어가서 출력 ( cspdiuxX% )

	// printf("type = %c\n", s->type);
	if (s->type == 'c')
		str_len += ft_put_c(s, ap);
	if (s->type == 's')
		str_len += ft_put_s(s, ap);
	// if (s->type == 'p')
	// 	str_len += ft_put_d(s, ap);
	if (s->type == 'd')
		str_len += ft_put_d(s, ap);
	if (s->type == 'i')
		str_len += ft_put_d(s, ap);
	if (s->type == 'u')
		str_len += ft_put_u(s, ap);
	// if (s->type == 'x')
	// 	str_len += ft_put_d(s, ap);
	// if (s->type == 'X')
	// 	str_len += ft_put_d(s, ap);
	if (s->type == '%')
		str_len += ft_put_c(s, ap);
	return (str_len);
}
