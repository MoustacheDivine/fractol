/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:21:15 by gbruscan          #+#    #+#             */
/*   Updated: 2024/11/02 03:11:51 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../minilibx/mlx42.h"
#include "libft.h"
#include <math.h>

#define WIDTH 1080
#define HEIGHT 720
#define MAX_ITER 100
#define MOVE_ARROW 0.005
#define ERROR_VALUE 1.7976931348623157E+308

typedef struct s_fract
{
	double		zx;
	double		zy;
	double		a;
	double		b;
	double		temp;
	int			iter;
	int			x;
	int			y;
	int			color;
	int			color_index;
}				t_fract;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fract		fract;
	int			width;
	int			height;
	double		ratio;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			type;
	int			max_iter;
}				t_mlx;

typedef struct s_mouse
{
	double		a;
	double		b;
	double		zoom;
	int			x;
	int			y;
}				t_mouse;

int				get_color(int iter, int color_index);
long double		ft_atolf(const char *str);
void			key_hook(mlx_key_data_t keydata, void *param);
void			draw_image(void *param);
void			clean_data(t_mlx *data);
int				data_init(t_mlx *data);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			resize_hook(int width, int height, void *param);
void			draw_mandelbrot(double a, double b, t_mlx *d);
void			calc_mandlebrot(t_fract *fract, double *a, double *b);
void			draw_julia(double a, double b, t_mlx *data);
void			calc_julia(t_fract *fract, double *a, double *b);
void			draw_burning_ship(double cx, double cy, t_mlx *data);
void			calc_burning_ship(t_fract *fract, double cx, double cy);
int				create_rgb(unsigned char r, unsigned char g, unsigned char b);
