/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_xmaj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:42:13 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/24 14:09:16 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_xmaj(va_list args)
{
	size_t			i;
	unsigned int	x;

	i = 0;
	x = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_hex(x, "0123456789ABCDEF", 1);
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	return (i);
}
