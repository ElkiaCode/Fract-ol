/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:21:20 by cparodi           #+#    #+#             */
/*   Updated: 2024/06/07 11:19:15 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_parsing_format(const char format, va_list args);
int		ft_make_c(va_list args);
int		ft_make_s(va_list args);
int		ft_make_p(va_list args);
int		ft_make_d(va_list args);
int		ft_make_u(va_list args);
int		ft_make_x(va_list args);
int		ft_make_xmaj(va_list args);
int		ft_make_percent(va_list args);

void	ft_putnbr_u_fd(unsigned int n, int fd);
void	ft_putnbr_hex(unsigned long n, char *base, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
