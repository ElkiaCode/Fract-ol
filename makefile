# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 11:15:18 by cparodi           #+#    #+#              #
#    Updated: 2024/09/18 15:55:41 by cparodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = fractol

# Files
SRC =	srcs/fractol.c \
		srcs/hooks.c \
		srcs/hooks2.c \
		srcs/mlx_pixel.c \
		srcs/fractal/mandelbrot.c \
		srcs/fractal/julia.c \
		srcs/utils/ft_strcmp.c \
		srcs/utils/ft_atof.c

MLX = ./include/minilibx-linux
PRINTF = ./srcs/utils/printf/libftprintf.a
SOURCES =		${SRC}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -o3 -g
RM		= rm -f

# Loading Bar
RESET		= \e[0m
UP			= \e[A

WHITE		= \e[0;1;97m
_WHITE		= \e[1;4;97m
RED			= \e[0;1;31m
GREEN		= \e[0;1;32m
_GREEN		= \e[1;4;32m

FILE_COUNT	= 0
FILE_TOTAL	= 8
BAR_SIZE	= ${shell expr 100 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_LOAD	= ${shell expr 23 \* ${FILE_COUNT} / ${FILE_TOTAL}}
BAR_REST	= ${shell expr 23 - ${BAR_LOAD}}

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
		@make -C ${MLX} > /dev/null 2>&1
		@make -C ./srcs/utils/printf > /dev/null 2>&1
		@${CC} ${CFLAGS} ${OBJECTS} ${PRINTF} -Lmlx_linux -lmlx_Linux -L${MLX} -Imlx_linux -lXext -lX11 -lm -lz -o ${EXE}
		@echo "\n\n${GREEN}[✓] - ${_GREEN}Fractol${GREEN} Successfully Compiled!${RESET}"
		@${RM} ${OBJECTS}

%.o:		%.c
		@${eval FILE_COUNT = ${shell expr ${FILE_COUNT} + 1}}
		@${CC} ${CFLAGS} -I/include -Imlx_linux -O3 -c $? -o $@
		@echo "${WHITE}[!] - Compilation loading...${RESET}"
		@printf "${WHITE}[${GREEN}%-.${BAR_LOAD}s${RED}%-.${BAR_REST}s${WHITE}] [%d/%d (%d%%)]${RESET}" "#######################" "#######################" ${FILE_COUNT} ${FILE_TOTAL} ${BAR_SIZE}
		@echo ""
		@echo "${UP}${UP}${UP}"

clean:
		@${RM} ${OBJECTS}
		@make -C ${MLX} clean > /dev/null
		@make -C ./srcs/utils/printf clean > /dev/null
		@echo "${WHITE}[!] - ${_WHITE}Fractol${WHITE} Successfully Cleaned!${RESET}"

fclean: clean
		@${RM} ${OBJECTS} ${EXE}
re:			fclean all

.PHONY: all clean fclean re
