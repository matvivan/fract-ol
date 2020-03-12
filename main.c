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

void		putpxl(t_pxl d, int x, int y, unsigned int color)
{
	int		i;

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
 
int			valid_option(int ac, char *k)
{
	if (ac == 2 && k[0] == '-')
		if (k[1] == 'K' || k[1] == 'B' || k[1] == 'J' || k[1] == 'M')
			return (0);
	return (1);
}

int			main(int argc, char **argv) 
{
	t_mlx	ptr;
	t_pxl	pxl;
	t_pln	plane;
	void	*v;

	if (valid_option(argc, argv[1])) {
		ft_putstr("Usage: fractol [-option]\n\
		\t -K Gustav Klimt art w/ fractals implemented into;\n\
		\t -B execute Buddhabrot interpretation of Mandelbrot Set;\n\
		\t -J execute Julia Set;\n\
		\t -M execute Mandelbrot Set;\n");
		return (1);
	}
	ptr.mlx = mlx_init();
	ptr.window = mlx_new_window(ptr.mlx, WIDTH, WIDTH, "Fract'matvivan");
	ptr.image = mlx_new_image(ptr.mlx, WIDTH, WIDTH);
	v = mlx_new_image(ptr.mlx, 100, 100);

	ptr.plane = &plane;
	plane.init_x = -2;
	plane.init_y = -2;
	plane.scale = 4;
	plane.max = 100;

	ptr.pxl = &pxl;
	pxl.addr = mlx_get_data_addr(ptr.image, &pxl.bpp, &pxl.size, &pxl.end);
	pxl.bpp /= 8;
	pxl.size /= pxl.bpp;

	if (argv[1][1] == 'M')
		mandelbrot(pxl, plane);
	if (argv[1][1] == 'J')
		motion_hook(500, 500, &ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.window, ptr.image, 0, 0);
	init_hooks(&ptr, argv[1][1]);
	return (0);
}
