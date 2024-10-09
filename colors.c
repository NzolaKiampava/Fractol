/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-07 22:46:28 by nkiampav          #+#    #+#             */
/*   Updated: 2024-09-07 22:46:28 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_color_sp(t_fractol *f)
{
	int	tmp_color;

	if (f->color == 0xFFFFFF)
		tmp_color = 0x336633;
	else
		tmp_color = f->color;
	if (f->color_pattern == 5)
		contrasted_color(f, tmp_color);
	else if (f->color_pattern == 6)
		opposite_color(f, f->color);
	else if (f->color_pattern == 7)
		graphic_color(f, f->color);
	else if (f->color_pattern == 8)
		multi_color(f, (int [8]){0xFF0000, 0xFF8F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0072, 0x9400E3, 0xFFFFFF}, 8);
}

static void	change_color_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		color_two(f, f->color);
	else if (f->color_pattern == 3)
		color_three(f, f->color);
	else if (f->color_pattern == 4)
		color_four(f, f->color);
	else
		change_color_sp(f);
}

void	color_shift(t_fractol *f)
{
	int	tmp_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		tmp_color = 0x336699;
	else
		tmp_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, tmp_color);
	else if (f->color_pattern == 1)
		multi_color(f, (int [4]){0x000000, tmp_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		change_color_striped(f);
}
