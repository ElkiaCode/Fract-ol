/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:05:18 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 17:47:46 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hooks(int keycode, t_fractal *win)
{
	if (keycode == 49)
		win->color = 0;
	if (keycode == 50)
		win->color = 8;
	if (keycode == 51)
		win->color = 16;
	if (keycode == 61)
		win->max_iter += 5;
	if (keycode == 45)
		win->max_iter -= 5;
	enter_key(keycode, win);
	first_stage_mandelbrot(win, 800, 800);
	return (0);
}

int	key_hooks_julia(int keycode, t_fractal *win)
{
	if (keycode == 49)
		win->color = 0;
	if (keycode == 50)
		win->color = 8;
	if (keycode == 51)
		win->color = 16;
	if (keycode == 61)
		win->max_iter += 5;
	if (keycode == 48)
	{
		if (win->p_color == 0)
			win->p_color = 1;
		else
			win->p_color = 0;
	}
	enter_key_julia(keycode, win);
	first_stage_julia(win, 800, 800);
	return (0);
}

int	enter_key_julia(int keycode, t_fractal *win)
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
	else
		ft_printf("Keycode %d pressed.\n", keycode);
	first_stage_julia(win, 800, 800);
	return (0);
}

int	mouse_key_julia(int keycode, int x, int y, t_fractal *win)
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
		first_stage_julia(win, 800, 800);
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
		first_stage_julia(win, 800, 800);
	}
	return (0);
}
