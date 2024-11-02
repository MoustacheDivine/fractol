/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 02:21:15 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 04:08:15 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long double	ft_parse_decimal(const char *str, int *i)
{
	long double	result;
	long double	fraction;

	result = 0.0;
	fraction = 0.1;
	if (!ft_isdigit(str[*i]))
		return (ERROR_VALUE + 1);
	while (ft_isdigit(str[*i]))
	{
		result += (str[*i] - '0') * fraction;
		fraction *= 0.1;
		(*i)++;
	}
	if (str[*i] != '\0')
		return (ERROR_VALUE + 1);
	return (result);
}

static long double	ft_parse_number(const char *str, int *i)
{
	long double	result;

	result = 0.0;
	if (!ft_isdigit(str[*i]))
		return (ERROR_VALUE + 1);
	while (ft_isdigit(str[*i]))
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		result += ft_parse_decimal(str, i);
	}
	return (result);
}

long double	ft_atolf(const char *str)
{
	long double	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_parse_number(str, &i);
	return (result * sign);
}

void	draw_image(void *param)
{
	t_mlx	*data;

	data = param;
	if (data->type == 0)
		draw_mandelbrot(0, 0, data);
	if (data->type == 1)
		draw_julia(data->fract.a, data->fract.b, data);
	if (data->type == 2)
		draw_burning_ship(0, 0, data);
}
