/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:42:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/31 20:44:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 플레그를 구하는 방법을 다시 생각해봐야할거같다.
int			ft_printf_flag(char *format)
{
}

int			ft_printf_format(char *format)
{
}

int			ft_printf_chk(char *format, va_list ap, int str_len)
{
	char	*flag;
	char	*format;
	int		i;

	i = 0;
	if (format[i] == '%')
	{
		format = ft_printf_format(format);
		flag = ft_printf_flag(flag);
		// 출력도중에 값이 오류가 나서 문자열로 출력을 해야하는경우 어떻게 처리를 해주어여하는가.
		// printf("% r   r    d", a);
		if (!format || !flag)
			ft_special_prt(format);
	else
		return (_ERROR);
}
