/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_event_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-08 12:22:55 by nkiampav          #+#    #+#             */
/*   Updated: 2024-09-08 12:22:55 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_for_fractal(int keycode, t_fractol *f)
{
	if (keycode == KEY_1 && f->type != M)
		f->type = M;
	else if (keycode == KEY_2 && f->type != J)
		f->type = J;
	else
		return (1);
	design_coordenates(f);
	draw_fractal(f);
	return (0);
}

int	handle_key(int key, t_fractol *f)
{
	if (key == ESC)
	{
		erase_fractol(f);
		return (0);
	}
	else if (key == KEY_SPACE)
		color_shift(f);
	else if (!key_for_fractal(key, f))
		return (1);
	else
		return (1);
	draw_fractal(f);
	return (0);
}
