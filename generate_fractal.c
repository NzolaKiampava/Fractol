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

static int	get_color(int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == MAX_ITER)
		return (0x000000);
	t = (double)iterations / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	draw_fractal(t_mlx *mlx, t_fractol *f)
{
	double	c_re;
	double	c_im;
	int		x;
	int		y;
	int		pixel;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c_re = f->min_re + x * f->re_factor;
			c_im = f->max_im - y * f->im_factor;
			if (f->type == 'M')
				f->color = mandelbrot(c_re, c_im);
			else if (f->type == 'J')
				f->color = julia(c_re, c_im, f->julia_re, f->julia_im);
			pixel = (x * mlx->bpp / 8) + (y * mlx->sline);
			if (f->color == MAX_ITER)
				*(int *)(mlx->data + pixel) = 0x000000;
			else
				*(int *)(mlx->data + pixel) = get_color(f->color);
		}
	}
}

void	update_fractal(t_mlx *mlx, t_fractol *fractal)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw_fractal(mlx, fractal);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
