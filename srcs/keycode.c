/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:33:35 by cparodi           #+#    #+#             */
/*   Updated: 2024/08/15 16:39:19 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_move(int x, int y, void *param)
{
	(void)param;
	printf("moving on (%d, %d)\n", x, y);
	return (0);
}

int	mouse_key(int keycode, int x, int y, t_fractal win)
{
	(void)win;
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
		win.scale *= 0.8;
	}
	else if (keycode == 5)
	{
		printf("zoom out (%d, %d)\n", x, y);
		win.scale /= 0.8;
	}
	fractal_mandelbrot(&win, 800, 800);
	return (0);
}

int	enter_key(int keycode, t_fractal win)
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
