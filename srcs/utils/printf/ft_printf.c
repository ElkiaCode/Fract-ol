/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:09:56 by cparodi           #+#    #+#             */
/*   Updated: 2024/06/07 10:55:16 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total;
	int		i;
	va_list	args;

	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total += ft_parsing_format(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total++;
		}
		i++;
	}
	va_end(args);
	return (total);
}
