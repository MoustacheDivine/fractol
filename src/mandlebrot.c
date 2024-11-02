/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:27:44 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 01:51:00 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandlebrot(t_fract *fract, double *a, double *b)
{
	fract->temp = fract->zx * fract->zx - fract->zy * fract->zy + *a;
	fract->zy = 2.0 * fract->zx * fract->zy + *b;
	fract->zx = fract->temp;
	fract->iter++;
}

void	draw_mandelbrot(double a, double b, t_mlx *data)
{
	t_fract	fract;

	fract = data->fract;
	fract.y = 0;
	while (fract.y < data->height)
	{
		fract.x = 0;
		while (fract.x < data->width)
		{
			a = data->xmin + fract.x * (data->xmax - data->xmin) / data->width;
			b = data->ymin + fract.y * (data->ymax - data->ymin) / data->height;
			fract.zx = 0.0;
			fract.zy = 0.0;
			fract.iter = 0;
			while ((fract.zx * fract.zx + fract.zy * fract.zy <= 4.0)
				&& fract.iter < MAX_ITER)
				calc_mandlebrot(&fract, &a, &b);
			fract.color = get_color(fract.iter, fract.color_index);
			mlx_put_pixel(data->img, fract.x, fract.y, fract.color);
			fract.x++;
		}
		fract.y++;
	}
}
