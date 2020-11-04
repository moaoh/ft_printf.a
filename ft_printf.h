/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:35:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/04 20:26:51 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF
#	define FT_PRINTF

#	include <stdarg.h>
#	include <stdlib.h>
#	include <unistd.h>

typedef struct	s_chk
{
	int			f_minus;
	int			f_zero;
	int			width;
	int			length;
	int			f_point;
	char		type;
}				t_chk;

#	define _ERROR -1

int			ft_printf(const char *format, ...);
int			ft_printf_format_type(char **format, va_list ap, int str_len);
t_chk		*ft_printf_flag_chk(char **point, va_list ap);

int			ft_prt(char *str, int len);

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);

#	endif
