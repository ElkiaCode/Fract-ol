/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparodi <cparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:53 by cparodi           #+#    #+#             */
/*   Updated: 2024/09/18 17:38:26 by cparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../srcs/utils/printf/ft_printf.h"
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
	int		color;
	int		p_color;
	t_nb	c;
}			t_fractal;

// utils

int			ft_strcmp(const char *s1, const char *s2);
double		ft_atof(const char *str);
void		zoom(t_fractal *fractal, int zoom_in, int x, int y);

// Mandelbrot fractal

void		fractal_mandelbrot(t_fractal *fractal, int argc, char **argv);
void		draw_first_mandelbrot(t_fractal *fractal, int y, int width,
				int height);
void		draw_mandelbrot(t_fractal *fractal, int x, int y);
int			mandelbrot(t_nb coord, int max_iter);
void		first_stage_mandelbrot(t_fractal *fractal, int width, int height);

// Julia fractal

void		fractal_julia(t_fractal *fractal, int argc, char **argv);
void		first_stage_julia(t_fractal *fractal, int width, int height);
void		draw_first_julia(t_fractal *fractal, int y, int width, int height);
void		draw_julia(t_fractal *fractal, int x, int y);
int			julia(t_nb coord, t_nb c, int max_iter);

// put pixels

void		my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
void		my_mlx_pixel_put_nocolor(t_fractal *fractal, int x, int y,
				int color);

// key control

int			enter_key(int keycode, t_fractal *win);
int			mouse_key(int keycode, int x, int y, t_fractal *win);
int			mouse_move(int x, int y, void *param);
int			close_window(t_fractal *win, void *param);
int			key_hooks(int keycode, t_fractal *win);
int			key_hooks_julia(int keycode, t_fractal *win);
int			enter_key_julia(int keycode, t_fractal *win);
int			mouse_key_julia(int keycode, int x, int y, t_fractal *win);

#endif
