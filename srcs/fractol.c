/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:11 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/10 14:32:21 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static char	*name_window(char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return ("Mandelbrot Fractal");
	else if (ft_strcmp(argv[1], "Julia") == 0)
		return ("Julia Fractal");
	else
	{
		printf("invalid input\n");
		exit(0);
	}
}

static void	Fractal_choose(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		fractal_mandelbrot(fractal, 800, 800, argc, argv);
	// else if (ft_strcmp(argv[1], "Julia") == 0)
	// 	fractal_Julia();
}

int	main(int argc, char **argv)
{
	t_fractal	win;
	char		*name;

	if (argc < 2)
	{
		printf("Enter one of these fractals as a parameter to launch the");
		printf(" program\n\nFractal : Julia\nFractal : Mandelbrot\n");
		exit(0);
	}
	name = name_window(argv);
	win.mlx = mlx_init();
	win.window = mlx_new_window(win.mlx, 800, 800, name);
	win.img = mlx_new_image(win.mlx, 800, 800);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
			&win.endian);
	Fractal_choose(&win, argc, argv);
	mlx_key_hook(win.window, enter_key, &win);
	mlx_mouse_hook(win.window, mouse_key, &win);
	mlx_hook(win.window, 6, (1L << 6), mouse_move, NULL);
	mlx_hook(win.window, 17, 0L, close_window, &win);
	mlx_loop(win.mlx);
}
