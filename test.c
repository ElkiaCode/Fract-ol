static char	*name_window(char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return ("Mandelbrot");
	return ("Nothing");
}

int	main(int argc, char **argv)
{
	t_fractal win;
	char *name;

	if (argc < 2)
	{
		printf("Usage: %s <fractal_name>\n", argv[0]);
		return (1);
	}
	name = name_window(argv);
	win.mlx = mlx_init();
	mlx_new_window(win.mlx, 800, 800, name);
	win.img = mlx_new_image(win.mlx, 800, 800);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length,
			&win.endian);
	win.center_re = -0.5;
	win.center_im = 0.0;
	win.scale = 4.0;
	win.max_iter = 100;
	fractal_mandelbrot(&win, 800, 800);
	mlx_key_hook(win.window, enter_key, &win);
	mlx_mouse_hook(win.window, mouse_key, &win);
	mlx_hook(win.window, 6, (1L << 6), mouse_move, NULL);
	mlx_loop(win.mlx);
}
