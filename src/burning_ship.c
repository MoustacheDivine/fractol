/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:49:30 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:03:24 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_burning_ship(t_fract *fract, double a, double b)
{
	fract->temp = fract->zx * fract->zx - fract->zy * fract->zy + a;
	fract->zy = fabs(2.0 * fract->zx * fract->zy) + b;
	fract->zx = fabs(fract->temp);
	fract->iter++;
}

void	draw_burning_ship(double a, double b, t_mlx *data)
{
	t_fract	fract;

	fract = data->fract;
	fract.y = 0;
	while (fract.y < data->height)
	{
		fract.x = 0;
		while (fract.x < data->width)
		{
			fract.zx = 0.0;
			fract.zy = 0.0;
			fract.iter = 0;
			a = data->xmin + fract.x * (data->xmax - data->xmin) / data->width;
			b = data->ymin + fract.y * (data->ymax - data->ymin)
				/ data->height;
			while (fract.iter < MAX_ITER && (fract.zx * fract.zx + fract.zy
					* fract.zy) <= 4.0)
				calc_burning_ship(&fract, a, b);
			fract.color = get_color(fract.iter, fract.color_index);
			mlx_put_pixel(data->img, fract.x, fract.y, fract.color);
			fract.x++;
		}
		fract.y++;
	}
}
