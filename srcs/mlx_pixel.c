/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:06:36 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 16:15:29 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_nocolor(t_fractal *fractal, int x, int y, int color)
{
	int	pos;

	pos = (y * fractal->line_length) + (x * fractal->bits_per_pixel / 8);
	fractal->addr[pos] = color;
	fractal->addr[pos + 1] = color;
	fractal->addr[pos + 2] = color;
}
