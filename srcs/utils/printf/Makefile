# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:30:05 by cparodi           #+#    #+#              #
#    Updated: 2024/06/07 14:26:10 by cparodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = 	ft_printf.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_strlen.c \
			ft_putstr_fd.c \
			ft_putnbr_u_fd.c \
			ft_putnbr_hex.c \
			ft_parsing_format.c \
			ft_make_c.c \
			ft_make_s.c \
			ft_make_p.c \
			ft_make_d.c \
			ft_make_u.c \
			ft_make_x.c \
			ft_make_xmaj.c \
			ft_make_percent.c

NAME    = libftprintf.a

OBJS    = ${SRCS:.c=.o}

LIBC    = ar rcs

CC      = cc

RM      = rm -f

CFLAGS  = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re run
