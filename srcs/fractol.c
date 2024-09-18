/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:11 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 17:37:33 by cparodi          ###   ########.fr       */
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

static void	fractal_choose(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		fractal_mandelbrot(fractal, argc, argv);
	else if (ft_strcmp(argv[1], "Julia") == 0)
		fractal_julia(fractal, argc, argv);
}

static void	ft_error(int argc)
{
	if (argc < 2)
	{
		ft_printf("Enter one of these fractals as a parameter to launch the");
		ft_printf(" program\n\nFractal : Julia <iter> <real> <imaginary>\n");
		ft_printf("Fractal : Mandelbrot <iter> \n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	win;
	char		*name;

	ft_error(argc);
	name = name_window(argv);
	win.mlx = mlx_init();
	win.window = mlx_new_window(win.mlx, 800, 800, name);
	win.img = mlx_new_image(win.mlx, 800, 800);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
			&win.endian);
	fractal_choose(&win, argc, argv);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		mlx_key_hook(win.window, key_hooks, &win);
		mlx_mouse_hook(win.window, mouse_key, &win);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		mlx_key_hook(win.window, key_hooks_julia, &win);
		mlx_mouse_hook(win.window, mouse_key_julia, &win);
	}
	mlx_hook(win.window, 6, (1L << 6), mouse_move, NULL);
	mlx_hook(win.window, 17, 0L, close_window, &win);
	mlx_loop(win.mlx);
}
