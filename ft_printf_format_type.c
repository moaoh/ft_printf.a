/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:40:37 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/04 20:21:04 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf_format_type(char **format, va_list ap, int *str_len)
{
	t_chk	*s;

	s = ft_printf_flag_chk(format, ap);
	printf("%d\n", s->f_minus);
	printf("%d\n", s->f_zero);
	printf("%d\n", s->width);
	printf("%d\n", s->length);
	printf("%d\n", s->f_point);
	printf("%c\n", s->type);
	// 이후 type에 따라서 값을 들어가서 출력
}
