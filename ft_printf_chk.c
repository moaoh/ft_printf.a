/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:56:04 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/03 16:03:24 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// format에 형식이 맞는지 확인
int		chk(char *c)
{
	if (c == 'c' || c == 's' || \
		c == 'd' || c == 'i' || \
		c == 'p' || c == 'u' || \
		c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

// 올바른 format인지 확인
int		chk_format(char *c)
{
	if (chk(c))
		return (1);
	else
		return (0);
}

// - , 0 , . , *
// 올바른 플레그인지 확인.
int		chk_flag(char *c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || \
									('0' <= c && c <= '9'))
		return (1);
	else
		return (0);
}
