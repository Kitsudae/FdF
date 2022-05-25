/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:16:38 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/05/25 21:39:21 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"
#include <stdio.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	zoom(int key, t_fdf *map)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS)
		map->zoom++;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS)
		map->zoom--;
	if (map->zoom < 1)
		map->zoom = 1;
	draw(map);
}

void	rotate(int key, t_fdf *map)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		map->angle += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		map->angle -= 0.05;
	draw(map);
}

int	deal_key(int key, t_fdf *map)
{
	if (key == 126)
		map->shift_y -= 10; //down key
	if (key == 125)
		map->shift_y += 10; //up key
	if (key == 123)
		map->shift_x -= 10; // left key
	if (key == 124)
		map->shift_x += 10; // right key
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, map);
		
	if (key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_8 || key == MAIN_PAD_8)
		rotate(key, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}


int	main(void)
{
	t_fdf	*map;
	char	*filename;

	filename = "test_maps/42.fdf";
	map = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(filename, map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1220, 1080, "Hello world!");
	map->angle = 0.5;
	draw(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}


