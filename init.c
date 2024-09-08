/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <nkiampav@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-07 22:55:03 by nkiampav          #+#    #+#             */
/*   Updated: 2024-09-07 22:55:03 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	image_initialization(t_fractol *f)
{
	int		pbb;
	int		size_line;
	int		endian;
	char	*data;

	f->palette = ft_calloc((MAX_ITER + 1), sizeof(int));
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	data = mlx_get_data_addr(f->img_ptr, &pbb, &size_line, &endian);
	f->data = data;
}

void	reinit_img(t_fractol *f)
{
	if (f->mlx_ptr && f->img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	if (f->palette)
		free(f->palette);
	if (f->data)
		f->data = NULL;
	image_initialization(f);
}

void	init(t_fractol *f)
{
    char    *str_msg;

	if (f->type == M)
		str_msg = "Fractal | MandelBrot";
	else if (f->type == J)
		str_msg = "Fractal | Julia";
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, str_msg);
	design_coordenates(f);
	color_shift(f);
}
