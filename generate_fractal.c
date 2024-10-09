/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:03:49 by nkiampav          #+#    #+#             */
/*   Updated: 2024/08/29 14:03:51 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	design_coordenates(t_fractol *f)
{
	if (f->type == J)
	{
		f->min_re = -2.0;
		f->max_re = 2.0;
		f->min_im = -2.0;
		f->max_im = f->min_im + (f->max_re - f->min_re) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_re = -2.0;
		f->max_re = 1.0;
		f->max_im = -1.5;
		f->min_im = f->max_im + (f->max_re - f->min_re) * HEIGHT / WIDTH;
	}
}

static void	put_color_pos_imxel(t_fractol *f, int x, int y, int color)
{
	int	index;

	index = x * 4 + y * WIDTH * 4;
	f->data[index] = (unsigned char)(color & 0xFF);
	f->data[index + 1] = (unsigned char)((color >> 8) & 0xFF);
	f->data[index + 2] = (unsigned char)((color >> 16) & 0xFF);
	f->data[index + 3] = (unsigned char)((color >> 24) & 0xFF);
}

static int	switch_fractal(t_fractol *f, double pos_re, double pos_im)
{
	int	num_iter;

	if (f->type == M)
		num_iter = mandelbrot(pos_re, pos_im);
	else if (f->type == J)
		num_iter = julia(f, pos_re, pos_im);
	return (num_iter);
}

void	draw_fractal(t_fractol *f)
{
	int		x;
	int		y;
	double	pos_re;
	double	pos_im;
	int		num_iter;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pos_re = f->min_re + (double)x * (f->max_re - f->min_re) / WIDTH;
			pos_im = f->max_im + (double)y * (f->min_im - f->max_im) / HEIGHT;
			num_iter = switch_fractal(f, pos_re, pos_im);
			put_color_pos_imxel(f, x, y, f->palette[num_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
