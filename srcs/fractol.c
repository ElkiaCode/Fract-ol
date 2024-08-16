/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:11 by cparodi           #+#    #+#             */
/*   Updated: 2024/08/15 16:35:08 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(void)
{
	t_fractal	win;

	win.mlx = mlx_init();
	win.window = mlx_new_window(win.mlx, 800, 800, "blurp!");
	win.img = mlx_new_image(win.mlx, 800, 800);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
			&win.endian);
	win.center_re = -0.5;
	win.center_im = 0.0;
	win.scale = 4.0;
	win.max_iter = 1000;
	fractal_mandelbrot(&win, 800, 800);
	mlx_key_hook(win.window, enter_key, NULL);
	mlx_mouse_hook(win.window, mouse_key, &win);
	mlx_hook(win.window, 6, (1L << 6), mouse_move, NULL);
	mlx_loop(win.mlx);
}
