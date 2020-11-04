/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_chk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:42:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/04 16:44:36 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_chk		*ft_chk_bzero(void)
{
	t_chk		*s;

	if (!(s = malloc(sizeof(t_chk) * 1)))
		return (NULL);
	s->f_minus = 0;
	s->f_zero = 0;
	s->width = 0;
	s->length = 0;
	s->f_point = 0;
	s->type = '\0';
	return (s);
}

void		*ft_chk_flag(char **point, t_chk *s)
{
	while (*point == '-' || *point == '0')
	{
		if (*point == '-')
			s->f_minus = 1;
		if (*point == '0')
			s->f_zero = 1;
		*point++;
	}
}

void		*ft_chk_width(char **point, t_chk *s, va_list ap)
{
	if (*point == '*')
		s->width = va_arg(ap, int);
	else
	{
		while ('0' <= *point && *point <= '9')
		{
			s->width *= 10;
			s->width = s->width + (*point - '0');
			*point++;
		}
	}
}

void		ft_chk_length(char **point, t_chk *s, va_list ap)
{
	if (*point == '*')
		s->length = va_arg(ap, int);
	else
	{
		while ('0' <= *point && *point <= '9')
		{
			s->length *= 10;
			s->length = s->length + (*point - '0');
			*point++;
		}
	}
}

void		ft_chk_type(char **point, t_chk *s)
{
	char		*str = "cspdiuxX%";

	while(*str)
	{
		if (*str == *point)
			s->type = *str;
		*str++;
	}
}

// printf("%-10.1d")
// %[0, -][0 ~ 9 or *].[0 ~ 9 or *]d
t_chk			*ft_printf_flag_chk(char **point, va_list ap)
{
	t_chk		*s;

	*point++;
	if (!(s = ft_chk_bzero()))
		return (NULL);
	ft_chk_flag(point, s);
	ft_chk_width(point, s, ap);
	if (*point == '.')
	{
		s->f_point = 1;
		*point++;
	}
	ft_chk_length(point, s, ap);
	ft_chk_type(point, s);

	return (s);
}
