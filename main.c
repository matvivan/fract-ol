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

unsigned int		palette(double iter)
{
	unsigned int	color;

	color = 0;
	if (iter <= 0.84)
	{
		iter /= 0.42; /* period from 0.0 to 2.0 */
		/*		 red		*/
		color += 237 * (1 - fabs(iter - 1));
		if (iter <= 1)
			color -= 140 * (0.5 - fabs(iter - 0.5));
		else
			color += 272 * (0.5 - fabs(iter - 1.5));
		color *= 0x100;
		/*		green		*/
		color += 255 * (1 - fabs(iter - 1));
		if (iter > 1)
			color += 84 * (0.5 - fabs(iter - 1.5));
		color *= 0x100;
		/*		 blue		*/
		color += 255 * (1 - pow(iter - 1, 2) * 0.52 * pow(6, (int)iter));
	}
	return (color);
}

unsigned int		ft_fatou(t_pxl d, t_cmpl z, t_cmpl c, float max)
{
	int				iter;
	double			sqr_re;
	double			sqr_im;

	iter = 0;
	while ((sqr_re = z.re * z.re) + (sqr_im = z.im * z.im) < 4 && iter < max)
	{
		z.im = z.im * (z.re + z.re) + c.im;
		z.re = sqr_re - sqr_im + c.re;
		++iter;
	}
	return (palette(iter / max));
}

void				successive(t_mlx *ptr, t_cmpl c, int chunk)
{
	int				i;
	int				j;
	t_cmpl			z;
	unsigned int	color;

	i = -1;
	while (++i < ptr->pxl->size)
	{
		z.re = 4.0 * i / ptr->pxl->size - 2;
		j = -1;
		while (++j < ptr->pxl->size)
		{
			z.im = 4.0 * j / ptr->pxl->size - 2;
			if (i % chunk == 0 || j % chunk == 0)
				color = ft_fatou(*(ptr->pxl), z, c, 100);
			putpxl(*(ptr->pxl), i, j, color);
		}
	}
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
}

void				fill(t_pxl data, double coef, float marg_re, float marg_im)
{
	long double		i;
	long double		j;
	t_cmpl			c;
	static float	max = 48;
	static double	scale = 4;
	static double	init_re = -2;
	static double	init_im = -2;

	if (coef != 1)
	{
		init_re += scale * (marg_re - coef / 2);
		init_im += scale * (marg_im - coef / 2);
		scale *= coef;
	}
	if (coef == 1)
		++max;
	else
		max *= 1.08 - max * max / 10000000;
	printf("%f: ", max);
	i = 0;
	while (i < data.size)
	{
		c.re = init_re + scale * i / (data.size - 1);
		j = 0;
		while (j < data.size)
		{
			c.im = init_im + scale * j / (data.size - 1);
			putpxl(data, i, j, ft_fatou(data, c, c, max));
			++j;
		}
		++i;
	}
	printf("%Lf, %Lf\n", c.re, c.im);
}

int					plane(int x, int y, t_mlx *ptr)
{
	t_cmpl			c;
	int				chunk;

	chunk = 2;
	c.re = 4.0 * x / ptr->pxl->size - 2;
	c.im = 4.0 * y / ptr->pxl->size - 2;
	while ((chunk /= 2))
		successive(ptr, c, chunk);
	return (1);
}

int					key_hook(int key, t_mlx *ptr)
{
	if (key == 53)
	{
		mlx_destroy_image(ptr->mlx, ptr->image);
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
	t_cmpl			c;

	if (button == 1)
	{
		fill(*ptr->pxl, 0.9, x * 1. / ptr->pxl->size, y * 1. / ptr->pxl->size);
	//	plane(x, y, ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	}
	if (button == 2)
	{
		c.re = 4.0 * x / ptr->pxl->size - 2;
		c.im = 4.0 * y / ptr->pxl->size - 2;
		printf("%x\n", ft_fatou(*ptr->pxl, c, c, 50));
	}
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

	mlx_mouse_hook(ptr.window, &mouse_hook, &ptr);
	mlx_key_hook(ptr.window, &key_hook, &ptr);
//	mlx_hook(ptr.window, 6, 0, &plane, &ptr);
	mlx_hook(ptr.window, 17, 0, (int (*)())&exit, NULL);
	mlx_loop(ptr.mlx);

	return (0);
}
