/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:56:49 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/06 19:59:41 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_print(int width, int len)
{
	if (width > 0)
	{
		while (width - len > 0)
		{
			write(1, " ", 1);
			width--;
		}
	}
}
