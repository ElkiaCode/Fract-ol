/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:12:23 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 15:32:10 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double	fraction(double result, int i, const char *str, double decimal)
{
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal /= 10.0;
			result += (str[i] - '0') * decimal;
			i++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 1.0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	result = fraction(result, i, str, decimal);
	return (result * sign);
}
