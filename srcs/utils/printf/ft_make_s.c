/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:47:51 by cparodi           #+#    #+#             */
/*   Updated: 2024/05/10 13:23:31 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_make_s(va_list args)
{
	char	*str;

	str = (char *)va_arg(args, char *);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}
