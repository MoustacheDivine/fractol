/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:23:07 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:08:37 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

int	color_red(int iter)
{
	double	normalize;

	if (iter == MAX_ITER)
		return (0xFFEFEFE0);
	normalize = (double)iter / MAX_ITER;
	if (normalize < 0.2)
		return (create_rgb(normalize * 5 * 255, 0, 0));
	else if (normalize < 0.4)
		return (create_rgb(255, ((normalize - 0.2) * 5 * 128), 0));
	else if (normalize < 0.6)
		return (create_rgb(255, (128 + (normalize - 0.4) * 5 * 127), 0));
	else if (normalize < 0.8)
		return (create_rgb(255, 255, ((normalize - 0.6) * 5 * 128)));
	else
		return (create_rgb(255, 255, (128 + (normalize - 0.8) * 5 * 127)));
}

int	color_blue(int iter)
{
	double	normalize;

	if (iter == MAX_ITER)
		return (0xFFEFEFE0);
	normalize = (double)iter / MAX_ITER;
	if (normalize < 0.2)
		return (create_rgb(0, 0, normalize * 5 * 255));
	else if (normalize < 0.4)
		return (create_rgb(0, (normalize - 0.2) * 5 * 128, 255));
	else if (normalize < 0.6)
		return (create_rgb(0, (128 + (normalize - 0.4) * 5 * 127), 255));
	else if (normalize < 0.8)
		return (create_rgb((normalize - 0.6) * 5 * 255, 255, 255));
	else
		return (create_rgb(255, 255, 255));
}

int	color_purple(int iter)
{
	double	normalize;

	if (iter == MAX_ITER)
		return (0xFFEFEFE0);
	normalize = (double)iter / MAX_ITER;
	if (normalize < 0.2)
		return (create_rgb(normalize * 5 * 128, 0, normalize * 5 * 255));
	else if (normalize < 0.4)
		return (create_rgb(128 + (normalize - 0.2) * 5 * 127, 0, 255));
	else if (normalize < 0.6)
		return (create_rgb(255, (normalize - 0.4) * 5 * 128, 255));
	else if (normalize < 0.8)
		return (create_rgb(255, 128 + (normalize - 0.6) * 5 * 127, 255));
	else
		return (create_rgb(255, 255, 255));
}

int	get_color(int iter, int color_index)
{
	int	(*colors[3])(int);

	colors[0] = &color_red;
	colors[1] = &color_blue;
	colors[2] = &color_purple;
	if (color_index == 1)
		return (color_blue(iter));
	if (color_index == 2)
		return (color_purple(iter));
	else
		return (color_red(iter));
}
