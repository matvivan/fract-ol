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

int					main(int argc, char **argv) 
{
	t_mlx			ptr;
	t_pxl			data;

	if (argc == 2) {
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
	ft_putstr("Usage: fractol [option]\n									\
	\t- 'Klimpt' Gustav art w/ fractals implemented into;\n					\
	\t- 'Buddhabrot' execute Buddhabrot interpretation of Mandelbrot Set;\n \
	\t- 'Julia' execute Julia Set;\n										\
	\t- 'Mandelbrot' execute Mandelbrot Set;\n");
	return (0);
}
