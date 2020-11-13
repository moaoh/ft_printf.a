/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:45:37 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/13 13:56:38 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *str)
{
	size_t			count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void				ft_bzero(void *ptr, size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
}
