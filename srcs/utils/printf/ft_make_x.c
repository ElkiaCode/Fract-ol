/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:27:35 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/10 16:40:41 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_x(va_list args)
{
	size_t			i;
	unsigned int	x;

	i = 0;
	x = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_hex(x, "0123456789abcdef", 1);
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	return (i);
}
