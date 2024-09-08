/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_striped.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-07 23:18:53 by nkiampav          #+#    #+#             */
/*   Updated: 2024-09-07 23:18:53 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_palette(t_fractol *f, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_ITER)
	{
		f->palette[i] = color;
		i += stripe;
	}
}

int	get_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	perc;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	perc = (percent / 100) * 256;
	trgb[0] = (rgb[0] + perc) - 256;
	trgb[1] = (rgb[1] + perc) - 256;
	trgb[2] = (rgb[2] + perc) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

void	color_two(t_fractol *f, int color)
{
	int	color2;

	color2 = get_percent_color(color, 50);
	fill_palette(f, color, 1);
	fill_palette(f, color2, 2);
	f->palette[MAX_ITER - 1] = 0;
}

void	color_three(t_fractol *f, int color)
{
	int		three[2];

	three[0] = get_percent_color(color, 33);
	three[1] = get_percent_color(color, 66);
	fill_palette(f, color, 1);
	fill_palette(f, three[0], 2);
	fill_palette(f, three[1], 3);
	f->palette[MAX_ITER - 1] = 0;
}

void	color_four(t_fractol *f, int color)
{
	int	four[3];

	four[0] = get_percent_color(color, 25);
	four[1] = get_percent_color(color, 50);
	four[2] = get_percent_color(color, 75);
	fill_palette(f, color, 1);
	fill_palette(f, four[0], 2);
	fill_palette(f, four[1], 3);
	fill_palette(f, four[2], 4);
	f->palette[MAX_ITER - 1] = 0;
}