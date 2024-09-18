/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:00:11 by cparodi           #+#    #+#             */
/*   Updated: 2024/06/07 11:08:32 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing_format(const char format, va_list args)
{
	if (format == 'c')
		return (ft_make_c(args));
	else if (format == 's')
		return (ft_make_s(args));
	else if (format == 'p')
		return (ft_make_p(args));
	else if (format == 'd' || format == 'i')
		return (ft_make_d(args));
	else if (format == 'u')
		return (ft_make_u(args));
	else if (format == 'x')
		return (ft_make_x(args));
	else if (format == 'X')
		return (ft_make_xmaj(args));
	else if (format == '%')
		return (ft_make_percent(args));
	return (0);
}
