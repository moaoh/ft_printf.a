/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:35:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/30 20:51:51 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF
#	define FT_PRINTF

#	include <stdarg.h>
#	include <stdlib.h>
#	include <unistd.h>

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);

int			ft_prt(char *str, int len);
int			ft_printf_chk(const char *format, va_list ap);



#	endif
