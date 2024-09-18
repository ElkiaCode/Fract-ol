/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:37:56 by cparodi           #+#    #+#             */
/*   Updated: 2024/06/07 11:24:37 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_d(va_list args)
{
	size_t	i;
	int		x;

	i = 0;
	x = (int)va_arg(args, int);
	ft_putnbr_fd(x, 1);
	if (x == 0)
		return (1);
	if (x < 0)
		i++;
	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}
