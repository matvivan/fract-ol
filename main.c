/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:08:43 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/16 19:03:07 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>


void				putpxl(t_pxl d, int x, int y, unsigned int color)
{
	int				i;

	i = 0;
	if (x >= 0 && x < d.size && y >= 0 && y < d.size)
		while (i < d.bpp)
		{
			if (d.end)
				d.addr[(x + y * d.size + 1) * d.bpp - 1 - i] = color % 256;
			else 
				d.addr[(x + y * d.size) * d.bpp + i] = color % 256;
			color /= 256;
			++i;
		}
}

unsigned int		palette(int iter)
{
	unsigned int color;

	color = 0;
	if (iter < 1)
		color = 0;
	else if (iter <= 160)
		color = (iter / 5 << 16) + ((7 + iter * 100 / 160) << 8) + (100 + iter * 103 / 160);
	else if (iter <= 420)
	{
		iter -= 160;
		color = ((32 + iter * 205 / 260) << 16) + ((107 + iter * 148 / 260) << 8) + (152 + iter * 103 / 260);
	}
	else if (iter <= 642)
	{
		iter -= 420;
		color = ((237 + iter * 18 / 222) << 16) + ((255 - iter * 85 / 222) << 8) + (255 - iter * 255 / 222);
	}
	else if (iter <= 857)
	{
		iter -= 642;
		color = ((255 - iter * 255 / 215) << 16) + ((170 - iter * 168 / 215) << 8);
	}
	else if (iter < 999)
	{
		iter -= 857;
		color = 0x000200 + iter * 170 / 142;
	}
	return (color);
}

unsigned int		mandelbrot(t_pxl d, t_cmpl z, t_cmpl c, float max)
{
	int				iter;
	double			old_re;
	double			smooth;

	iter = 0;
	while (z.re * z.re + z.im * z.im < 4 && ++iter < max)
	{
		old_re = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * old_re * z.im + c.im;
	}
	return (palette(1000 * iter / max));/*
	smooth = log2(log2(z.re * z.re + z.im * z.im) / 2);
	return (palette((int)(sqrt(iter + 10 - smooth) * 256) % 1024 / 1.024));*/
}

void				fill(t_pxl data, double coef, float marg_x, float marg_y)
{
	long double		i;
	long double		j;
	t_cmpl			c;
	static float	max = 50;
	static double	scale = 4;
	static double	init_x = -2;
	static double	init_y = -2;

	if (coef != 1)
	{
		init_x += scale * (marg_x - coef / 2);
		init_y += scale * (marg_y - coef / 2);
		scale *= coef;
	}
	max *= 1.08 - max * max / 1000000;
	printf("%f: ", max);
	i = 0;
	while (i < data.size)
	{
		c.re = init_x + scale * i / (data.size - 1);
		j = 0;
		while (j < data.size)
		{
			c.im = init_y + scale * j / (data.size - 1);
			putpxl(data, i, j, mandelbrot(data, c, c, max));
			++j;
		}
		++i;
	}
	printf("%Lf, %Lf\n", c.re, c.im);
}

int					key_hook(int key, t_mlx *ptr)
{
	if (key == 53)
	{
		mlx_destroy_image(ptr->mlx, ptr->image);
//		system("leaks fractol | grep Leak");
		exit(0);
	}
	else if (key == 69)
	{
		fill(*ptr->pxl, 1, 1, 1);
		mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	}
	else
		printf("pressed %d\n", key);
	return (0);
}

int					mouse_hook(int button, int x, int y, t_mlx *ptr)
{
	fill(*ptr->pxl, 0.8, x * 1. / ptr->pxl->size, y * 1. / ptr->pxl->size);
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	return (0);
}

int					main(void) 
{
	t_mlx			ptr;
	t_pxl			data;

	ptr.mlx = mlx_init();
	ptr.window = mlx_new_window(ptr.mlx, WIDTH, WIDTH, "Fract'matvivan");
	ptr.image = mlx_new_image(ptr.mlx, WIDTH, WIDTH);
	ptr.pxl = &data;

	data.addr = mlx_get_data_addr(ptr.image, &data.bpp, &data.size, &data.end);
	data.bpp /= 8;
	data.size /= data.bpp;
	fill(data, 1, 1, 1);
	mlx_put_image_to_window(ptr.mlx, ptr.window, ptr.image, 0, 0);

	mlx_key_hook(ptr.window, &key_hook, &ptr);
	mlx_mouse_hook(ptr.window, &mouse_hook, &ptr);
	mlx_hook(ptr.window, 17, 0, (int (*)())&exit, NULL);
	mlx_loop(ptr.mlx);

	return (0);
}
