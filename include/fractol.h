/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:53 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/10 14:27:35 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_nb
{
	double	real;
	double	imaginary;
}			t_nb;

typedef struct s_fractal
{
	double	center_re;
	double	center_im;
	double	scale;
	int		max_iter;
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fractal;

// utils

int			ft_strcmp(const char *s1, const char *s2);

// mandelbrot

void		fractal_mandelbrot(t_fractal *fractal, int width, int height,
				int argc, char **argv);
void		draw_first(t_fractal *fractal, int y, int width, int height);
void		draw(t_fractal *fractal, int x, int y, int width, int height);
int			mandelbrot(t_nb coord, int max_iter);
void		first_stage(t_fractal *fractal, int width, int height);

// put pixels

void		my_mlx_pixel_put(t_fractal *data, int x, int y, int color);

// key control

int			enter_key(int keycode, t_fractal *win);
int			mouse_key(int keycode, int x, int y, t_fractal *win);
int			mouse_move(int x, int y, void *param);
int			close_window(void *param);

#endif
