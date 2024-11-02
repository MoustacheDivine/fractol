/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:00:08 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:52:57 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	data_init(t_mlx *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data->mlx)
		return (1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_terminate(data->mlx);
		return (1);
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return (1);
	data->width = WIDTH;
	data->height = HEIGHT;
	data->ratio = (double)data->width / (double)data->height;
	data->ymax = 2.0;
	data->ymin = -2.0;
	data->xmax = 2.0 * data->ratio;
	data->xmin = -2.0 * data->ratio;
	return (0);
}

void	clean_data(t_mlx *data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(0);
}

int	select_fractal(t_mlx *data, int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "m") == 0)
			return (data->type = 0, 1);
		if (ft_strcmp(argv[1], "j") == 0)
			return (data->type = 1, 1);
		if (ft_strcmp(argv[1], "b") == 0)
			return (data->type = 2, 1);
		return (0);
	}
	if (argc == 3 || argc >= 5)
		return (0);
	if (argc == 4)
	{
		if (ft_strcmp(argv[1], "j") == 0)
		{
			if (ft_atolf(argv[2]) != ERROR_VALUE
				&& ft_atolf(argv[3]) != ERROR_VALUE)
				return (data->type = 1, data->fract.a = ft_atolf(argv[2]),
					data->fract.b = ft_atolf(argv[3]), 1);
		}
	}
	return (0);
}

void	ft_error(void)
{
	ft_printf("Argument(s) invalide(s)\n\n");
	ft_printf("Voici la liste des arguments valides :\n\n");
	ft_printf("m pour l'ensemble de Mandelbrot\n");
	ft_printf("j ([a][b]) pour l'ensemble de Julia\n");
	ft_printf("b pour Burning ship\n\n");
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	ft_memset(&data, 0, sizeof(t_mlx));
	if (select_fractal(&data, argc, argv))
	{
		if (data_init(&data))
			return (1);
		mlx_resize_hook(data.mlx, resize_hook, &data);
		mlx_key_hook(data.mlx, key_hook, &data);
		mlx_scroll_hook(data.mlx, scroll_hook, &data);
		mlx_loop_hook(data.mlx, draw_image, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_error();
	clean_data(&data);
	return (0);
}
