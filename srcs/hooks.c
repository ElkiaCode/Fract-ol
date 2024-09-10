/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:33:35 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/05 15:38:42 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	zoom(t_fractal *fractal, int zoom_in, int x, int y)
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
	printf("moving on (%d, %d)\n", x, y);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	printf("Exiting...\n");
	exit(0);
}

int	mouse_key(int keycode, int x, int y, t_fractal *win)
{
	if (keycode == 1)
	{
		printf("left click on (%d, %d)\n", x, y);
	}
	else if (keycode == 3)
	{
		printf("right click on (%d, %d)\n", x, y);
	}
	else if (keycode == 2)
	{
		printf("wheel click on (%d, %d)\n", x, y);
	}
	else if (keycode == 4)
	{
		printf("zoom in (%d, %d)\n", x, y);
		zoom(win, 1, x, y);
	}
	else if (keycode == 5)
	{
		printf("zoom out (%d, %d)\n", x, y);
		zoom(win, 0, x, y);
	}
	first_stage(win, 800, 800);
	return (0);
}

int	enter_key(int keycode, t_fractal *win)
{
	(void)win;
	if (keycode == KEY_ESC)
	{
		printf("Exiting...\n");
		exit(0);
	}
	else if (keycode == KEY_W || keycode == 65362)
	{
		printf("Moving up.\n");
	}
	else if (keycode == KEY_A || keycode == 65361)
	{
		printf("Moving left.\n");
	}
	else if (keycode == KEY_S || keycode == 65364)
	{
		printf("Moving down.\n");
	}
	else if (keycode == KEY_D || keycode == 65363)
	{
		printf("Moving right.\n");
	}
	else
	{
		printf("Keycode %d pressed.\n", keycode);
	}
	return (0);
}
