/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:44:05 by nkiampav          #+#    #+#             */
/*   Updated: 2024/09/02 08:44:06 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window(int exit_code, t_fractol *f)
{
	if (!f)
		exit(exit_code);
	if (f->palette)
		free(f->palette);
	if (f->img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	if (f->win_ptr && f->mlx_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_loop_end(f->mlx_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(exit_code);
}

int	erase_fractol(t_fractol *f)
{
	close_window(0, f);
	return (0);
}

static void	zoom(t_fractol *f, double zoom_scale)
{
	double	center_re;
	double	center_im;
	double	width_re;
	double	height_im;

	center_re = (f->min_re + f->max_re) / 2;
	center_im = (f->min_im + f->max_im) / 2;
	width_re = f->max_re - f->min_re;
	height_im = f->max_im - f->min_im;
	f->min_re = center_re - (width_re * zoom_scale) / 2;
	f->max_re = center_re + (width_re * zoom_scale) / 2;
	f->min_im = center_im - (height_im * zoom_scale) / 2;
	f->max_im = center_im + (height_im * zoom_scale) / 2;
}

static void	relocate(t_fractol *f, double dst, char dir)
{
	double	center_re;
	double	center_im;

	center_re = f->max_re - f->min_re;
	center_im = f->max_im - f->min_im;
	if (dir == 'R')
	{
		f->min_re += center_re * dst;
		f->max_re += center_re * dst;
	}
	else if (dir == 'L')
	{
		f->min_re -= center_re * dst;
		f->max_re -= center_re * dst;
	}
	else if (dir == 'D')
	{
		f->min_im -= center_im * dst;
		f->max_im -= center_im * dst;
	}
	else if (dir == 'U')
	{
		f->min_im += center_im * dst;
		f->max_im += center_im * dst;
	}
}

int	mouse_hook(int key, int x, int y, t_fractol *f)
{
	if (key == MOUSE_WHEEL_UP)
	{
		zoom(f, 0.5);
		x = x - WIDTH / 2;
		y = y - HEIGHT / 2;
		if (x < 0)
			relocate(f, (double)(-x) / WIDTH, 'L');
		else if (x > 0)
			relocate(f, (double)x / WIDTH, 'R');
		if (y < 0)
			relocate(f, (double)(-y) / HEIGHT, 'U');
		else if (y > 0)
			relocate (f, (double)y / HEIGHT, 'D');
	}
	else if (key == MOUSE_WHEEL_DOWN)
		zoom(f, 2);
	else
		return (0);
	draw_fractal(f);
	return (0);
}
