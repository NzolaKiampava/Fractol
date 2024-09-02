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

int	close_window(t_fractol *fractal, t_mlx *mlx)
{
	if (!fractal)
		exit(0);
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr && mlx->img_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_loop_end(mlx->mlx_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(0);
}

int	handle_key(int key, t_fractol *fractal, t_mlx *mlx)
{
	if (key == ESC)
	{
		close_window(fractal, mlx);
		return (0);
	}
	return (0);
}

static void	mup_calculation(t_fractol *fractal, double m_re, double m_im)
{
	fractal->min_re = m_re + (fractal->min_re - m_re) / ZOOM_FACTOR;
	fractal->max_re = m_re + (fractal->max_re - m_re) / ZOOM_FACTOR;
	fractal->min_im = m_im + (fractal->min_im - m_im) / ZOOM_FACTOR;
	fractal->max_im = m_im + (fractal->max_im - m_im) / ZOOM_FACTOR;
}

static void	mdown_calculation(t_fractol *fractal, double m_re, double m_im)
{
	fractal->min_re = m_re + (fractal->min_re - m_re) * ZOOM_FACTOR;
	fractal->max_re = m_re + (fractal->max_re - m_re) * ZOOM_FACTOR;
	fractal->min_im = m_im + (fractal->min_im - m_im) * ZOOM_FACTOR;
	fractal->max_im = m_im + (fractal->max_im - m_im) * ZOOM_FACTOR;
}

int	mouse_hook(int button, int x, int y, void *param)
{
	double		mouse_re;
	double		mouse_im;
	t_mlx		*mlx;
	t_fractol	*fractal;

	mlx = (t_mlx *)param;
	fractal = (t_fractol *)(mlx + 1);
	mouse_re = fractal->min_re + x * fractal->re_factor;
	mouse_im = fractal->max_im - y * fractal->im_factor;
	if (button == MOUSE_WHEEL_UP)
		mup_calculation(fractal, mouse_re, mouse_im);
	else if (button == MOUSE_WHEEL_DOWN)
		mdown_calculation(fractal, mouse_re, mouse_im);
	fractal->re_factor = (fractal->max_re - fractal->min_re) / (WIDTH - 1);
	fractal->im_factor = (fractal->max_im - fractal->min_im) / (HEIGHT - 1);
	update_fractal(mlx, fractal);
	return (0);
}
