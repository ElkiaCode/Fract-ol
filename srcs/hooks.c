/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:33:35 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 17:55:40 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom(t_fractal *fractal, int zoom_in, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.1;
	mouse_re = fractal->center_re + (x - 800 / 2) * fractal->scale / 800;
	mouse_im = fractal->center_im + (y - 800 / 2) * fractal->scale / 800;
	if (zoom_in)
	{
		fractal->scale /= zoom_factor;
	}
	else
	{
		fractal->scale *= zoom_factor;
	}
	fractal->center_re = mouse_re - (x - 800 / 2) * fractal->scale / 800;
	fractal->center_im = mouse_im - (y - 800 / 2) * fractal->scale / 800;
}

int	mouse_move(int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int	close_window(t_fractal *win, void *param)
{
	(void)param;
	(void)win;
	ft_printf("Exiting...\n");
	// mlx_destroy_image(win->mlx, win->img);
	// free(win->addr);
	exit(0);
}

int	mouse_key(int keycode, int x, int y, t_fractal *win)
{
	if (keycode == 4)
	{
		zoom(win, 1, x, y);
		if (win->p_color == 1)
		{
			if (win->color == 22)
				win->color = 0;
			else
				win->color += 2;
		}
	}
	else if (keycode == 5)
	{
		zoom(win, 0, x, y);
		if (win->p_color == 1)
		{
			if (win->color == 22)
				win->color = 0;
			else
				win->color += 2;
		}
	}
	first_stage_mandelbrot(win, 800, 800);
	return (0);
}

int	enter_key(int keycode, t_fractal *win)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Exiting...\n");
		// mlx_destroy_image(win->mlx, win->img);
		// free(win->addr);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == 65362)
		win->center_im += 0.1;
	else if (keycode == KEY_A || keycode == 65361)
		win->center_re += 0.1;
	else if (keycode == KEY_S || keycode == 65364)
		win->center_im -= 0.1;
	else if (keycode == KEY_D || keycode == 65363)
		win->center_re -= 0.1;
	if (keycode == 48)
	{
		if (win->p_color == 0)
			win->p_color = 1;
		else
			win->p_color = 0;
	}
	first_stage_mandelbrot(win, 800, 800);
	return (0);
}
