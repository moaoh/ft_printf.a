/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:35:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/06 20:34:06 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF
#	define FT_PRINTF

#	include <stdarg.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>

typedef struct	s_chk
{
	int			f_minus;
	int			f_zero;
	int			width;
	int			f_point;
	int			length;
	char		type;
}				t_chk;

#	define _ERROR -1

// main part
int			ft_printf(const char *format, ...);
int			ft_format_type(char **format, va_list ap);
t_chk		*ft_flag_chk(char **point, va_list ap);

// utils
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);

// type
int			ft_put_c(t_chk *s, va_list ap);
int			ft_put_d(t_chk *s, va_list ap);
int			ft_put_u(t_chk *s, va_list ap);
int			ft_put_s(t_chk *s, va_list ap);

//printf_flag
void		ft_width_print(int width, int len);



#	endif
