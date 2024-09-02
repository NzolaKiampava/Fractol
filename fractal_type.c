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

int	julia(double z_re, double z_im, double c_re, double c_im)
{
	double	z_re2;
	double	z_im2;
	double	new_re;
	double	new_im;
	int		n;

	n = 0;
	while (n < MAX_ITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		new_re = z_re2 - z_im2 + c_re;
		new_im = 2.0 * z_re * z_im + c_im;
		z_re = new_re;
		z_im = new_im;
		++n;
	}
	return (n);
}
