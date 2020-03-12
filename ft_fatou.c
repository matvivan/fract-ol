/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:46:13 by matvivan          #+#    #+#             */
/*   Updated: 2020/03/09 10:46:14 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		palette(double iter)
{
	unsigned int	color;

	color = 0;
	if (iter <= 0.84)
	{
		iter /= 0.42; /* adjust to period from 0.0 to 2.0 */
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

/*	Function Fatou is Z[new] = Z[old] + C^2		*/
	iter = 0;
	while ((sqr_re = z.re * z.re) + (sqr_im = z.im * z.im) < 4 && iter < max)
	{
		z.im = z.im * (z.re + z.re) + c.im;
		z.re = sqr_re - sqr_im + c.re;
		++iter;
	}
	return (palette(iter / max));
}

int	    			julia(t_pxl data, t_cmpl c)
{
	int				i;
	int				j;
	t_cmpl			z;
	unsigned int	color;

	i = 0;
	while (i < data.size)
	{
		z.re = 4.0 * i / data.size - 2;
		j = 0;
		while (j < data.size)
		{
			z.im = 4.0 * j / data.size - 2;
			color = ft_fatou(data, z, c, 100);
			putpxl(data, i, j, color);
			++j;
		}
		++i;
	}
    return (0);
}

void				mandelbrot(t_pxl data, t_pln pln)
{
	long double		i;
	long double		j;
	t_cmpl			z;
	unsigned int	color;

	i = 0;
	while (i < data.size)
	{
		z.re = pln.init_x + pln.scale * i / data.size;
		j = 0;
		while (j < data.size)
		{
			z.im = pln.init_y + pln.scale * j / data.size;
			color = ft_fatou(data, z, z, pln.max);
			putpxl(data, i, j, color);
			++j;
		}
		++i;
	}
}

int					motion_hook(int x, int y, t_mlx *ptr)
{
	t_cmpl			c;

	c.re = 4.0 * x / ptr->pxl->size - 2;
	c.im = 4.0 * y / ptr->pxl->size - 2;
	julia(*ptr->pxl, c);
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	return (0);
}