/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:15:37 by nkiampav          #+#    #+#             */
/*   Updated: 2024/08/19 16:36:53 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

/* Dimensions */
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
# define ZOOM_FACTOR 1.2

/* KEYS */
# define CLOSE_BTN 17
# define ESC 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

// en => endian, sline => size_line
typedef struct i_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		sline;
	int		en;
}	t_mlx;

typedef struct i_fractol
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	double	julia_re;
	double	julia_im;
	char	type;
	int		color;
}	t_fractol;

// TYPES OF FRACTALS
int		mandelbrot(double c_re, double c_im);
int		julia(double z_re, double z_im, double c_re, double c_im);

// MESSAGES
void	usage_msg(void);
void	invalid_arg_msg(void);

// EVENTS FUNCTIONS
int		close_window(t_fractol *fractal, t_mlx *mlx);
int		handle_key(int key, t_fractol *fractal, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, void *param);

// UTILS
double	ft_atof(const char *str);

//GENERATE FRACTALS
void	draw_fractal(t_mlx *mlx, t_fractol *fractal);
void	update_fractal(t_mlx *mlx, t_fractol *fractal);

#endif
