/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:57:44 by cparodi           #+#    #+#             */
/*   Updated: 2024/06/07 11:08:33 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_p(va_list args)
{
	unsigned long	address;
	void			*ptr;
	int				i;

	i = 0;
	ptr = (void *)va_arg(args, void *);
	address = (unsigned long)ptr;
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(address, "0123456789abcdef", 1);
	while (address != 0)
	{
		address /= 16;
		i++;
	}
	return (i + 2);
}
