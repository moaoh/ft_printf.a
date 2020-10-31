/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:35:30 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/31 19:49:37 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF
#	define FT_PRINTF

#	include <stdarg.h>
#	include <stdlib.h>
#	include <unistd.h>

#	define _ERROR -1

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);

#	endif
