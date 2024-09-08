/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-08 13:46:50 by nkiampav          #+#    #+#             */
/*   Updated: 2024-09-08 13:46:50 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_values(t_fractol *f)
{
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->img_ptr = NULL;
	f->data = NULL;
	f->type = -1;
	f->min_re = 0;
	f->max_re = 0;
	f->min_im = 0;
	f->max_im = 0;
	f->c_re = 0;
	f->c_im = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}