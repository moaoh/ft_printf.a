/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:42:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/30 21:06:48 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_find(char *main, char *flag, va_list ap)
{
	if (main == "c")
		ft_printf_char(flag, main, ap);
	else if (main == "s")
		ft_printf_char(flag, main, ap);
	else if (main == "p")
	else if (main == "d")
		ft_printf_int(flag, main, ap);
	else if (main == "i")
	else if (main == "u")
	else if (main == "x")
}

// % 이후 어떤 플래그(. * 0) 가 들어오는지 확인
char		ft_printf_chk_flag(const char *format)
{
	// 플래그 이후 공백값이 들어오는것은 건너 뛰고, 공백 이후 다른 문자들이 들어오는데 그 문자들이 관련이 없다면 그냥 문자열로 출력.
	// 관련이 있는 문자열들이라면 가지고 출력.
	// 일단은 플래그만 정리하여 담는 함수
}

// % 이후 d, f, c, s 등 어떤것이 들어오는지 찾음
char		ft_printf_chk_main(const char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (('a' <= format[i] && format[i] <= 'z'))
		{
			if (format[i] == 'c' || format[i] == 's' \
				|| format[i] == 'p' || format[i] == 'd' \
				|| format[i] == 'i' || format[i] == 'u' \
				|| format[i] == 'x')
				return (format[i]);
			else
				return (NULL);
		}
		else if (!('0' <= format[i] && format[i] <= '9') && format[i] != ' ')
			return (NULL);
		i++;
	}
}

// % 이후 어떤 플래그가 들어오는지 확인
int		ft_printf_chk(const char *format, va_list ap)
{
	int		i;
	int		temp;
	char	*flag;
	char	*main;

	i = 0;
	if (format[i] == '%')
	{
		// flag에 내용을 담음. (. * 0)
		flag = ft_printf_chk_flag(format);
		// main에 내용을 담음. (d, f, c, s)
		main = ft_printf_chk_main(format);
		if (!main)
		{
			temp = ft_prt()
		}
		ft_find(main, flag, ap);
	}

}
