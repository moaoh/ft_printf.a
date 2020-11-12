/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:55:52 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/12 13:07:42 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strdup(const char *s)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	len = ft_strlen(s);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		count(long long n)
{
	int			len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void		ft_print(char *str, long long n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char			*ft_itoa(long long n)
{
	char		*str;
	int			len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	ft_print(str, n, len - 1);
	return (str);
}
