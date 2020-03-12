/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:17:45 by matvivan          #+#    #+#             */
/*   Updated: 2020/03/09 10:17:48 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_hook(int button, int x, int y, t_mlx *ptr)
{
	if (button == 5)
	{
		ptr->plane->init_x += ptr->plane->scale * (marg_re - coef / 2);
		ptr->plane->init_y += ptr->plane->scale * (marg_im - coef / 2);
		ptr->plane->scale *= 1.01;
		mandelbrot(*ptr->pxl, *ptr->plane);
		mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	}
	else if (button == 4)
	{
		init_re += scale * (marg_re - coef / 2);
		init_im += scale * (marg_im - coef / 2);
		ptr->plane->scale *= 0.99;
		mandelbrot(*ptr->pxl, *ptr->plane);
		mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->image, 0, 0);
	}
	return (0);
}

int					key_hook(int key, t_mlx *ptr)
{
	if (key == 53)
	{
//		mlx_destroy_image(ptr->mlx, ptr->image);
		system("leaks fractol | grep Leak");
		exit(0);
	}
	else
	{
		ft_putnbr(key);
		ft_putstr(" pressed\n");
	}
	return (0);
}

void				init_hooks(t_mlx *ptr, char key)
{
	if (key == 'M')
		mlx_mouse_hook(ptr->window, &mouse_hook, &ptr);
	mlx_key_hook(ptr->window, &key_hook, &ptr);
	if (key == 'J')
		mlx_hook(ptr->window, 6, 3, &motion_hook, ptr);
	mlx_hook(ptr->window, 17, 0, (int (*)())&exit, NULL);
	mlx_loop(ptr->mlx);
}
