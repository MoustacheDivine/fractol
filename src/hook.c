/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:25:07 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:11:38 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	resize_hook(int width, int height, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	data->width = width;
	data->height = height;
	mlx_resize_image(data->img, data->width, data->height);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_mlx	*data;
	t_mouse	mouse;

	data = param;
	(void)xdelta;
	mlx_get_mouse_pos(data->mlx, &mouse.x, &mouse.y);
	mouse.a = data->xmin + mouse.x * (data->xmax - data->xmin) / data->width;
	mouse.b = data->ymin + mouse.y * (data->ymax - data->ymin) / data->height;
	mouse.zoom = 0.1;
	if (ydelta > 0)
	{
		data->xmin = mouse.a + (data->xmin - mouse.a) * (1 - mouse.zoom);
		data->xmax = mouse.a + (data->xmax - mouse.a) * (1 - mouse.zoom);
		data->ymin = mouse.b + (data->ymin - mouse.b) * (1 - mouse.zoom);
		data->ymax = mouse.b + (data->ymax - mouse.b) * (1 - mouse.zoom);
	}
	else if (ydelta < 0)
	{
		data->xmin = mouse.a + (data->xmin - mouse.a) * (1 + mouse.zoom);
		data->xmax = mouse.a + (data->xmax - mouse.a) * (1 + mouse.zoom);
		data->ymin = mouse.b + (data->ymin - mouse.b) * (1 + mouse.zoom);
		data->ymax = mouse.b + (data->ymax - mouse.b) * (1 + mouse.zoom);
	}
}

void	color_hook(mlx_key_data_t keydata, t_mlx *data)
{
	if (keydata.key == MLX_KEY_C)
		data->fract.color_index = 0;
	if (keydata.key == MLX_KEY_V)
		data->fract.color_index = 1;
	if (keydata.key == MLX_KEY_B)
		data->fract.color_index = 2;
}

void	arrow_hook(mlx_key_data_t keydata, t_mlx *data)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		data->xmin -= (data->xmax - data->xmin) * MOVE_ARROW;
		data->xmax -= (data->xmax - data->xmin) * MOVE_ARROW;
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		data->xmin += (data->xmax - data->xmin) * MOVE_ARROW;
		data->xmax += (data->xmax - data->xmin) * MOVE_ARROW;
	}
	else if (keydata.key == MLX_KEY_UP)
	{
		data->ymin -= (data->ymax - data->ymin) * MOVE_ARROW;
		data->ymax -= (data->ymax - data->ymin) * MOVE_ARROW;
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		data->ymin += (data->ymax - data->ymin) * MOVE_ARROW;
		data->ymax += (data->ymax - data->ymin) * MOVE_ARROW;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		clean_data(data);
	else if (keydata.key == 67 || keydata.key == 86 || keydata.key == 66)
		color_hook(keydata, data);
	else
		arrow_hook(keydata, data);
}
