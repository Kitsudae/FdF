/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 20:04:54 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/06/16 20:28:42 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	ft_module(float x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	trans2dinto3d(float *x, float *y, int z, t_fdf *map)
{
	*x = (*x - *y) * cos(map->angle);
	*y = (*x + *y) * sin(map->angle) - 3*z;
}

void	bresenham_line(float x1, float y1, float x2, float y2, t_fdf *map)
{
	float	x_step;
	float	y_step;
	float	max_step;
	int		z1;
	int		z2;

	z1 = map->matrix[(int)y1][(int)x1];
	z2 = map->matrix[(int)y2][(int)x2];
	//zoom
	x1 *= map->zoom;
	x2 *= map->zoom;
	y1 *= map->zoom;
	y2 *= map->zoom;
	//color
	if (z1 > 0 || z2 > 0)
		map->color = 0x00FF0000;
	else
		map->color = 0x00FFFFFF;
	//3D
	//trans2dinto3d(&x1, &y1, z1, map);
	//trans2dinto3d(&x2, &y2, z2, map);
	//shift
	x1 += map->shift_x;
	y1 += map->shift_y;
	x2 += map->shift_x;
	y2 += map->shift_y;
	x_step = x2 - x1;
	y_step = y2 - y1;
	if (ft_module(x_step) > ft_module(y_step))
		max_step = ft_module(x_step);
	else
		max_step = ft_module(y_step);
	x_step /= max_step;
	y_step /= max_step;
	while ((int)(x2 - x1) > 0 || (int)(y2 - y1) > 0)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, map->color);
		x1 += x_step;
		y1 += y_step;
	}
}

void	draw(t_fdf *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				bresenham_line(x, y, (x + 1), y, map);
			if (y < map->height - 1)
				bresenham_line(x, y, x, (y + 1), map);
			x++;
		}
		y++;
	}
}
