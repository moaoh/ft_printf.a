# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 14:04:43 by junmkang          #+#    #+#              #
#    Updated: 2020/11/06 14:04:43 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_flag_chk.c ft_flag_print.c ft_format_type.c ft_itoa.c ft_printf_utils.c \
		ft_put_c.c ft_put_d.c ft_put_p.c ft_put_s.c ft_put_u.c ft_put_x.c ft_put_xlarge.c

CC = gcc
RM = rm -rf
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all
