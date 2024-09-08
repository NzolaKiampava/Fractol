/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:48:01 by nkiampav          #+#    #+#             */
/*   Updated: 2024/08/28 10:48:03 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		n;

	z_re = c_re;
	z_im = c_im;
	n = 0;
	while (n < MAX_ITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		++n;
	}
	return (n);
}

int	julia_shift(int x, int y, t_fractol *f)
{
	f->c_re = f->min_re + (double)x * (f->max_re - f->min_re) / WIDTH;
	f->c_im = f->max_im + (double)y * (f->min_im - f->max_im) / HEIGHT;
	draw_fractal(f);
	return (0);
}

int	julia(t_fractol *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITER)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->c_im;
		zr = zr * zr - zi * zi + f->c_re;
		zi = tmp;
		n++;
	}
	return (n);
}
