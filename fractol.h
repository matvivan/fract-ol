/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 19:34:12 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/25 19:36:26 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# include "libft/libft.h"
# include "miniLibX/mlx.h"
# include <math.h>

typedef struct	s_complex
{
	long double	re;
	long double	im;
}				t_cmpl;

typedef struct	s_pixel
{
	char		*addr;
	int			bpp;
	int			size;
	int			end;
}				t_pxl;

typedef struct s_plane
{
	float		init_x;
	float		init_y;
	float		scale;
	int			max;
}				t_pln;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*image;
	t_pxl		*pxl;
	t_pln		*plane;
}				t_mlx;

void			putpxl(t_pxl d, int x, int y, unsigned int color);
int				motion_hook(int x, int y, t_mlx *ptr);
void			mandelbrot(t_pxl data, t_pln pln);
unsigned int	ft_fatou(t_pxl d, t_cmpl z, t_cmpl c, float max);
int				julia(t_pxl data, t_cmpl c);
void			init_hooks(t_mlx *ptr, char key);

#endif
