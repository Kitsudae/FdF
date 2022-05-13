/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:16:38 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/05/13 22:27:53 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

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
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int		hook_mousedown(int key, int x, int y, t_fdf *map)
{
	(void)x;
	if (y < 0)
		return (0);
	map->mouse_down |= 1 << key;
	return (0);
}

int		hook_mouseup(int button, t_fdf *mlx, int x, int y)
{
	(void)x;
	(void)y;
	mlx->mouse_down &= ~(1 << button);
	return (0);
}

//void	draw(t_fdf *map);

int	main(void)
{
	t_fdf	*map;
	char	*filename;
	// int		i;
	// int		j;
	//void	*mlx;
	//void	*mlx_win;
	//t_data	img;

	filename = "test_maps/42.fdf";
	map = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(filename, map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1220, 1080, "Hello world!");
	map->zoom = 40;
	draw(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	//mlx_key_hook(map->win_ptr, hook_mousedown, map);
	// int	mlx_hook(void *win_ptr, int x_event, int x_mask,
    //              int (*funct)(), void *param);
	mlx_hook(map->win_ptr, 5, 0, hook_mouseup, map);
	mlx_loop(map->mlx_ptr);
}


	//bresenham_line(10, 10, 1000, 1000, 20, map);
	// img.img = mlx_new_image(map->mlx_ptr, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//bresenham_line(10, 10, 1000, 1000, map);
	//mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img.img, 0, 0);

	// //square
	// i = 100;
	// j = 100;
	// while (j < 1000)
	// {
	// 	while(i < 1000)
	// 	{
	// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// 		i++;
	// 	}
	// 	my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// 	j = j + 1;
	// 	i = 100;
	// }
	// //triangle
	// i = 100;
	// j = 100;
	// while (j < 1000)
	// {
	// 	i = 100;
	// 	while(i <= j)
	// 	{
	// 		my_mlx_pixel_put(&img, i, j, 0x000000FF);
	// 		i++;
	// 	}
	// 	j++;
	// }

	// draw map
	// 	i = 0;
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 	{
	// 		printf("%2.0d ", map->matrix[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }

