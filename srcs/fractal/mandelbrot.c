/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:19:52 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 17:27:19 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mandelbrot(t_nb coord, int max_iter)
{
	t_nb	ite_evo;
	t_nb	ite_evo_stock;
	int		iter;

	ite_evo.imaginary = 0.0;
	ite_evo.real = 0.0;
	iter = 0;
	while ((ite_evo.real * ite_evo.real + ite_evo.imaginary
			* ite_evo.imaginary) <= 4.0 && iter < max_iter)
	{
		ite_evo_stock.imaginary = 2 * ite_evo.real * ite_evo.imaginary;
		ite_evo_stock.real = ite_evo.real * ite_evo.real - ite_evo.imaginary
			* ite_evo.imaginary;
		ite_evo.real = ite_evo_stock.real + coord.real;
		ite_evo.imaginary = ite_evo_stock.imaginary + coord.imaginary;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_nb	coord;
	int		iter;
	int		color;
	int		width;
	int		height;

	width = 800;
	height = 800;
	if (x >= width)
		return ;
	coord.real = fractal->center_re + (x - width / 2) * fractal->scale / width;
	coord.imaginary = fractal->center_im + (y - height / 2) * fractal->scale
		/ height;
	iter = mandelbrot(coord, fractal->max_iter);
	color = 0;
	if (iter < fractal->max_iter)
		color = (iter * 255 / fractal->max_iter) << fractal->color;
	if (fractal->p_color == 1)
		my_mlx_pixel_put(fractal, x, y, color);
	else if (fractal->p_color == 0)
		my_mlx_pixel_put_nocolor(fractal, x, y, color);
	draw_mandelbrot(fractal, x + 1, y);
}

void	draw_first_mandelbrot(t_fractal *fractal, int y, int width, int height)
{
	if (y >= height)
		return ;
	draw_mandelbrot(fractal, 0, y);
	draw_first_mandelbrot(fractal, y + 1, width, height);
}

void	first_stage_mandelbrot(t_fractal *fractal, int width, int height)
{
	draw_first_mandelbrot(fractal, 0, width, height);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
}

void	fractal_mandelbrot(t_fractal *fractal, int argc, char **argv)
{
	int	width;
	int	height;

	width = 800;
	height = 800;
	fractal->center_re = -0.5;
	fractal->center_im = 0.0;
	fractal->scale = 4.0;
	if (argc < 3)
		fractal->max_iter = 50;
	else
		fractal->max_iter = atoi(argv[2]);
	first_stage_mandelbrot(fractal, width, height);
}
