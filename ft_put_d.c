/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:59:15 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/06 20:04:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int
// 안받는 플래그가 없다고 보면 됨
// -, 0, ., *
// d i u x X p
int		ft_put_d(t_chk *s, va_list ap)
{
	int		d;
	int		d_len;

	d = va_arg(ap, int);
	if (d < 0)
		write(1, "-", 1);
	// if (s->f_point == 1)
	// 	if (s->length >= 1)
	// 	{
	// 		while ()
	// 	}
	return (d_len);
}
