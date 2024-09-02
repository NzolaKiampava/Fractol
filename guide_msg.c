/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiampav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:26:57 by nkiampav          #+#    #+#             */
/*   Updated: 2024/08/28 12:26:59 by nkiampav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	welcome_message(void)
{
	ft_putendl_fd("\033[1;33m", 1);
	ft_putendl_fd("+===============================================+", 1);
	ft_putendl_fd("                   FRACT'OL                    ", 1);
	ft_putendl_fd("+===============================================+\n", 1);
}

void	usage_msg(void)
{
	welcome_message();
	ft_putendl_fd("\033[1;39mUsage: ./fractol [M | J]\033[0m\n", 1);
	ft_putendl_fd("M: Mandelbrot\nJ: Julia\n", 1);
	ft_putendl_fd("\033[1;36mJulia Usage: ./fractol J <re> <im>", 1);
	ft_putendl_fd("For Julia. Ex: ./fractol J -0.800616 -0.100090\n", 1);
	exit(1);
}

void	invalid_arg_msg(void)
{
	ft_putendl_fd("\033[1;31mInvalid fractal type.", 1);
	ft_putendl_fd("Use 'M' for Mandelbrot or 'J' for Julia.\033[0m\n", 1);
	exit(1);
}
