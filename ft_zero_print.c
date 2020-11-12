/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:30:57 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/12 16:31:07 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_zero_print(t_chk *s, int long_len, int *final_len, int d_minus)
{
	int		d_temp_minus;

	d_temp_minus = d_minus;
	if (s->f_zero == 1)
	{
		if ((s->width > 0 && s->precision == 0 && s->f_point == 0) || \
			(s->f_point == 1 && s->precision < 0))
		{
			if (d_temp_minus == 1)
				ft_prt_minus(&d_temp_minus);
			*final_len += ft_precision_print(s->width, long_len);
		}
		else
			*final_len += ft_width_print(s->width, long_len);
	}
	else
		*final_len += ft_width_print(s->width, long_len);
	return (d_temp_minus);
}
