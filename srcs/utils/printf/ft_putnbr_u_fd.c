/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:42:23 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/10 15:26:14 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
