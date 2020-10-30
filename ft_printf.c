/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:33 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/30 20:52:27 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prt(char *str, int len)
{
	write(1, str, len);
}

static int		*ft_answer(const char *format, va_list ap)
{
	int			answer_len;
	size_t		format_len;
	char		*chk_p;
	int			*temp;
	size_t		i;

	i = 0;
	answer_len = 0;
	format_len = ft_strlen(format_len);
	while (i < format_len)
	{
		chk_p = ft_strchr(format + i, '%');
		if (chk_p)
		{
			answer_len += ft_prt(format + i, chk_p);
			if (!(temp = ft_printf_chk(chk_p, ap)) || temp < 0)
				return (-1);
			answer_len = answer_len + temp;
			i += (int)chk_p;
		}
		else
		{
			answer_len += ft_prt(format + i, format_len - i);;
			break ;
		}
	}
	return (answer_len);
}

// main
int				ft_printf(const char format, ...)
{
	va_list		ap;
	int			str_len;

	va_start(ap, format);
	// aswer을 통해서 str에 최종값을 담아야함
	if (!(str_len = ft_answer(format, ap)))
		return (-1);
	return (str_len);
}

// a = 232323
// (number - len_a)

// ' ' 에 따른 연산

// a = len >= number ? 1 : number - len_a;
// if (len_a >= number)
// 	1;
// else if (len_a < number)
// 	(number - len_a)

// pirntf("% d")
// 출력 값을 기준으로 부호가 있으면 공백 미적용
// 출력 값을 기준으로 부호가 없으면 공백 적용

// printf("%010.3f", 1.0);
// 000001.000%
