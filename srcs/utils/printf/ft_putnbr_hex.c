/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:29:50 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/10 16:47:04 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_run(unsigned long n, char *base, int fd)
{
	int	i;

	i = ft_strlen(base);
	if (n > 0)
	{
		ft_putnbr_run(n / i, base, fd);
		ft_putchar_fd(base[n % i], fd);
	}
}

void	ft_putnbr_hex(unsigned long n, char *base, int fd)
{
	if (n == 0)
		ft_putchar_fd(base[0], fd);
	else
		ft_putnbr_run(n, base, fd);
}
