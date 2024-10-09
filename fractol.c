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

static int	cmp_param(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	check_set(t_fractol *f, char **av)
{
	if (cmp_param(av[1], "mandelbrot", 'm', '1'))
		f->type = M;
	else if (cmp_param(av[1], "julia", 'j', '2'))
		f->type = J;
	else
		usage_msg(f);
}

static void	julia_check(t_fractol *f, int ac, char **av)
{
	if (f->type != J || ac == 2)
	{
		f->c_re = -0.799667;
		f->c_im = -0.091000;
		return ;
	}
	if (ac == 3)
		usage_msg(f);
	if (!ft_strchr(av[2], '.'))
		usage_msg(f);
	if (!ft_strchr(av[3], '.'))
		usage_msg(f);
	f->c_re = ft_atof(av[2]);
	f->c_im = ft_atof(av[3]);
	if (f->c_re > 2.0 || f->c_re < -2.0)
		usage_msg(f);
	if (f->c_im >= 2.0 || f->c_im <= -2.0)
		usage_msg(f);
}

static void	handle_arg(t_fractol *f, int argc, char **argv)
{
	check_set(f, argv);
	if (f->type != J && argc > 3)
		usage_msg(f);
	else if (f->type == J && argc > 5)
		usage_msg(f);
	julia_check(f, argc, argv);
	get_color(f, argc, argv);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	reset_values(&f);
	if (argc < 2)
		usage_msg(&f);
	handle_arg(&f, argc, argv);
	init(&f);
	draw_fractal(&f);
	mlx_hook(f.win_ptr, CLOSE_BTN, 0, erase_fractol, &f);
	mlx_key_hook(f.win_ptr, handle_key, &f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_loop(f.mlx_ptr);
}
