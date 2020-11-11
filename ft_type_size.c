/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:47:15 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/11 19:51:07 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_d_size(long long d)
{
	int		count;

	count = 0;
	while (d >= 1)
	{
		d /= 10;
		count++;
	}
	return (count);
}

int			ft_x_size(unsigned int x)
{
	int		count;

	count = 0;
	while (x >= 1)
	{
		x /= 16;
		count++;
	}
	return (count);
}

int			ft_p_size(long long p)
{
	int		count;

	count = 0;
	while (p >= 1)
	{
		p /= 16;
		count++;
	}
	return (count);
}
