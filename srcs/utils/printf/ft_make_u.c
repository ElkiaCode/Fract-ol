/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:32 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/10 13:44:59 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_u(va_list args)
{
	size_t			i;
	unsigned int	x;

	i = 0;
	x = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_u_fd(x, 1);
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}
