/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:31:55 by nkiampav          #+#    #+#             */
/*   Updated: 2024/08/20 15:32:00 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init(t_fractol *fractal)
{
	double	aspect_ratio;
	double	range_re;
	double	range_im;

	if (fractal->type == 'J')
	{
		fractal->min_re = -2.0;
		fractal->max_re = 2.0;
		fractal->min_im = -1.5;
		fractal->julia_re = 0.355;
		fractal->julia_im = 0.355;
	}
	else
	{
		aspect_ratio = (double)HEIGHT / (double)WIDTH;
		fractal->min_re = -2.0;
		fractal->max_re = 2.0;
		fractal->min_im = -1.5;
		fractal->min_im = -2.0 * aspect_ratio;
	}
	range_re = fractal->max_re - fractal->min_re;
	fractal->max_im = fractal->min_im + range_re * HEIGHT / WIDTH;
	fractal->re_factor = range_re / (WIDTH - 1);
	range_im = fractal->max_im - fractal->min_im;
	fractal->im_factor = range_im / (HEIGHT - 1);
}

static void	julia_check(t_fractol *fractal, char **argv)
{
	if (!ft_strchr(argv[2], '.'))
		usage_msg();
	if (!ft_strchr(argv[3], '.'))
		usage_msg();
	fractal->julia_re = ft_atof(argv[2]);
	fractal->julia_im = ft_atof(argv[3]);
	if (fractal->julia_re > 2.0 || fractal->julia_re < -2.0)
		usage_msg();
	if (fractal->julia_im >= 2.0 || fractal->julia_im <= -2.0)
		usage_msg();
}

char	*put_str_msg(t_fractol *fractal)
{
	char	*str_msg;

	if (fractal->type == 'M')
		str_msg = "Fractal | MandelBrot";
	else if (fractal->type == 'J')
		str_msg = "Fractal | Julia";
	return (str_msg);
}

static void	handle_arg(t_fractol fractal, int argc, char **argv)
{
	if (argc < 2)
		usage_msg();
	else if (argc == 3 || argc > 4)
		usage_msg();
	fractal->type = argv[1][0];
	if (fractal->type != 'M' && fractal->type != 'J')
		invalid_arg_msg();
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_fractol	fractal;
	char		*str_msg;

	handle_arg(&fractal, argc, argv);
	init(&fractal);
	if (fractal.type == 'J')
	{
		if (argc == 4)
			julia_check(&fractal, argv);
	}
	str_msg = put_str_msg(&fractal);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, str_msg);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.sline, &mlx.en);
	draw_fractal(&mlx, &fractal);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, CLOSE_BTN, 0, close_window, NULL);
	mlx_key_hook(mlx.win_ptr, handle_key, NULL);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
