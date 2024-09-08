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
# define HEIGHT 800
# define MAX_ITER 100

/* KEYS */
# define CLOSE_BTN 17
# define ESC 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define KEY_SPACE 32
# define KEY_1 49
# define KEY_2 50

/* FRACTALS TYPES */
# define M 1
# define J 2

typedef struct fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	double	c_re;
	double	c_im;
	int		type;
	int		color;
	int		*palette;
	int		color_pattern;
}	t_fractol;

// RESER FRACTAL
void	reset_values(t_fractol *fractal);

// INITIALIZATIONS
void	init(t_fractol *fractal);
void	reinit_img(t_fractol *fractal);

// TYPES OF FRACTALS
int		mandelbrot(double c_re, double c_im);
int		julia_shift(int x, int y, t_fractol *fractal);
int		julia(t_fractol *fractal, double z_re, double z_im);

// GUIDE MESSAGES
void	usage_msg(t_fractol *fractal);

// EVENTS FUNCTIONS
void	close_window(int exit_code, t_fractol *fractal);
int		erase_fractol(t_fractol *f);
int		handle_key(int key, t_fractol *fractal);
int		mouse_hook(int key, int x, int y, t_fractol *fractal);

// UTILS
//void	reset_values(t_fractol *f);
double	ft_atof(const char *str);
void	get_color(t_fractol *fractal, int ac, char **av);

// GENERATE FRACTALS
void	draw_fractal(t_fractol *fractal);
void	design_coordenates(t_fractol *fractal);

// COLORS
void	color_shift(t_fractol *fractal);

// RGB COLORS - INTERPOLATE
void	set_color_mono(t_fractol *fractal, int color);
void	multi_color(t_fractol *fractal, int colors[4], int n);

// RGB COLORS - SPECIAL
void	opposite_color(t_fractol *fractal, int color);
void	contrasted_color(t_fractol *fractal, int color);
void	graphic_color(t_fractol *fractal, int color);

// RGB COLORS - STRIPED
int		get_percent_color(int color, double percent);
void	color_two(t_fractol *fractal, int color);
void	color_three(t_fractol *fractal, int color);
void	color_four(t_fractol *fractal, int color);

#endif
