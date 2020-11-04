/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:45:37 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/03 17:32:03 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

int		ft_atoi(const char *str)
{
	unsigned int		sum;
	unsigned int		num;
	int					i;

	num = 1;
	i = 0;
	while (str[i] && (str[i] == 32 || (9 <= str[i] && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num *= -1;
		i++;
	}
	sum = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (num * sum);
}
